#include "daemonize.h"

#include "../logging.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <paths.h>
#include <signal.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace nidevice_grpc {

static stop_callback signal_stop = NULL;
static std::string pid_path;
static int pid_fd = -1;

void catch_close(int sig) {
  const char* signal_description = "?";
  switch(sig)
  {
  case SIGINT:
    signal_description = "interrupt";
    break;
  case SIGTERM:
    signal_description = "terminate";
    break;
  case SIGHUP:
    signal_description = "hangup";
    break;
  default:
    break;
  }

  logging::log(logging::Level_Info, "handling signal: %d (%s)", sig, signal_description);
  if (signal_stop) {
    signal_stop();
  }

  if (close(pid_fd) < 0) {
    logging::log(logging::Level_Warning, "failed to close pid file: %d (%s)", errno, strerror(errno));
  }
  if (unlink(pid_path.c_str()) < 0) {
    logging::log(logging::Level_Warning, "failed to unlink pid file: %d (%s)", errno, strerror(errno));
  }
  exit(EXIT_SUCCESS);
}

int create_pidfile(const std::string& identity) {
  int size = snprintf(NULL, 0, _PATH_VARRUN "%s.pid", identity.c_str());
  pid_path.resize(size, ' ');
  if (snprintf(&pid_path[0], size + 1, _PATH_VARRUN "%s.pid", identity.c_str()) > size) {
    logging::log(logging::Level_Error, "creating pid path failed");
    exit(EXIT_FAILURE);
  }

  size = snprintf(NULL, 0, "%d\n", getpid());
  std::string pid_str(size, ' ');
  if (snprintf(&pid_str[0], size + 1, "%d\n", getpid()) > size) {
    logging::log(logging::Level_Error, "creating pid string failed");
    exit(EXIT_FAILURE);
  }

  int fd = open(pid_path.c_str(), O_RDWR|O_CREAT, 0644);
  if (fd < 0) {
    logging::log(logging::Level_Error, "creating pid file failed: %d (%s)", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (lockf(fd, F_TLOCK, 0) < 0) {
    logging::log(logging::Level_Error, "locking pid file failed (likely already running): %d (%s)", errno, strerror(errno));
    close(fd);
    exit(EXIT_FAILURE);
  }
  if (write(fd, pid_str.c_str(), size) != static_cast<ssize_t>(pid_str.length())) {
    logging::log(logging::Level_Error, "writing pid file failed: %d (%s)", errno, strerror(errno));
    close(fd);
    exit(EXIT_FAILURE);
  }
  if (ftruncate(fd, size) < 0) {
    logging::log(logging::Level_Error, "truncating pid file failed: %d (%s)", errno, strerror(errno));
    close(fd);
    exit(EXIT_FAILURE);
  }
  return fd;
}

void daemonize(stop_callback signal_stop_, const std::string& identity) {
  // Fork off the parent process to get into the background
  pid_t pid = fork();
  if (pid < 0) {
    logging::log(logging::Level_Error, "initial fork failed: %d (%s)", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Success: Let the parent terminate
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // The child process becomes session leader to detach from the terminal
  if (setsid() < 0) {
    logging::log(logging::Level_Error, "setsid failed: %d (%s)", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Fork off for the second time to get rid of the session leader
  pid = fork();
  if (pid < 0) {
    logging::log(logging::Level_Error, "second fork failed: %d (%s)", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Success: Let the parent terminate
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // Clear umask to give daemon complete control of file permissions
  umask(0);

  // Change the working directory to the root directory
  if (chdir("/") < 0) {
    logging::log(logging::Level_Error, "chdir failed: %d (%s)", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Close all open file descriptors
  for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
    close(x);
  }

  // Redirect standard files to /dev/null
  if (freopen("/dev/null", "r", stdin) == NULL) {
    logging::log(logging::Level_Error, "redirecting stdin to /dev/null: %d (%s)", errno, strerror(errno));
  }
  if (freopen("/dev/null", "w", stdout) == NULL) {
    logging::log(logging::Level_Error, "redirecting stdout to /dev/null: %d (%s)", errno, strerror(errno));
  }
  if (freopen("/dev/null", "w", stderr) == NULL) {
    logging::log(logging::Level_Error, "redirecting stderr to /dev/null: %d (%s)", errno, strerror(errno));
  }

  // We're fully operational, catch signals.
  signal_stop = signal_stop_;
  if (signal(SIGINT, catch_close) == SIG_ERR) {
    logging::log(logging::Level_Error, "failed to register SIGINT: %d (%s)", errno, strerror(errno));
  }
  if (signal(SIGTERM, catch_close) == SIG_ERR) {
    logging::log(logging::Level_Error, "failed to register SIGTERM: %d (%s)", errno, strerror(errno));
  }
  if (signal(SIGHUP, catch_close) == SIG_ERR) {
    logging::log(logging::Level_Error, "failed to register SIGHUP: %d (%s)", errno, strerror(errno));
  }

  // Now that we're fully daemonized, write our PID file and ensure we're the only daemon.
  pid_fd = create_pidfile(identity);
}

}  // namespace nidevice_grpc
