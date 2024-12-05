#include "sideband_manager.h"
#include "data_moniker_service.h"

void SidebandManager::start_sideband_thread(const std::string& address, int port) {
    if (sideband_socket_thread && sideband_socket_thread->joinable()) {
        stop_sideband_thread();
    }

    stop_flag.store(false);
    sideband_socket_thread = std::make_unique<std::thread>(RunSidebandSocketsAccept, address.c_str(), port, std::ref(stop_flag));
}

void SidebandManager::stop_sideband_thread() {
    stop_flag.store(true);
    if (sideband_socket_thread && sideband_socket_thread->joinable()) {
        sideband_socket_thread->join();
    }
    sideband_socket_thread.reset();
}
