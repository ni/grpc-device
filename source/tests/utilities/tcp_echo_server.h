#include <arpa/inet.h>
#include <memory>
#include <string>
#include <thread>
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

class TcpEchoServer
{
public:
    TcpEchoServer(const std::string& portNumber)
    : portNumber_(portNumber)
    , server_fd_(-1)
    {
    }

    ~TcpEchoServer()
    {
    }

    int start()
    {
        return start_server_session();
    }

    void stop()
    {
        close_server_session();
    }

private:
    int start_server_session()
    {
#ifdef _WIN32
        WSADATA wsa_data;
        WSAStartup(MAKEWORD(2, 2), &wsa_data);
#endif
        server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd_ == -1) {
            return -1;
        }
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_address.sin_port = htons(std::stoi(portNumber_));

        if (bind(server_fd_, (struct sockaddr*)&server_address, sizeof(server_address)) == 0) {
            server_thread_ = std::thread(&TcpEchoServer::run_server, this, server_fd_);
            return 0;
        }
        else {
            return -1;
        }

    }

    void run_server(SOCKET server_fd) {
        listen(server_fd, 1);
        SOCKET client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            return;
        }
        std::thread([this, client_fd]() {
            handle_client(client_fd);
        }).detach();
    }

    void close_server_session()
    {
        server_thread_.join();
#ifdef _WIN32
        closesocket(server_fd_);
        WSACleanup();
#else
        close(server_fd_);
#endif
    }

    void handle_client(SOCKET client_fd)
    {
        auto session = std::make_shared<TcpEchoSession>(client_fd);
        session->start();
    }

    std::string portNumber_;
    SOCKET server_fd_;
    std::thread server_thread_;
};
