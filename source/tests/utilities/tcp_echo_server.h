#include <iostream>
#include <memory>
#include <cstring>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#ifndef _WIN32
typedef int SOCKET;
#endif

class TcpEchoSession : public std::enable_shared_from_this<TcpEchoSession> {
public:
    TcpEchoSession(SOCKET socket_fd)
    : socket_fd_(socket_fd)
    {
    }

    ~TcpEchoSession() {
#ifdef _WIN32
    closesocket(socket_fd_);
#else
    close(socket_fd_);
#endif
    }

    void start()
    {
        do_read();
    }

private:
    void do_read()
    {
        auto self(shared_from_this());
        char buffer[max_length] = {0};
        int n = recv(socket_fd_, buffer, max_length, 0);
        if (n > 0) {
            do_write(buffer, n);
        }
    }

    void do_write(const char* data, int length)
    {
        auto self(shared_from_this());
        int n = send(socket_fd_, data, length, 0);
        if (n > 0) {
            do_read();
        }
    }

    static const int max_length = 256;
    SOCKET socket_fd_;
};