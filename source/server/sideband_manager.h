#ifndef SIDEBAND_MANAGER_H
#define SIDEBAND_MANAGER_H

#include <thread>
#include <string>
#include <atomic>

class SidebandManager {
public:
    void start_sideband_thread(const std::string& address, int port);
    void stop_sideband_thread();

private:
    std::atomic<bool> stop_flag {false};
    std::unique_ptr<std::thread> sideband_socket_thread;
};

#endif // SIDEBAND_MANAGER_H