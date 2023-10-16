#include <cstring>
#include <memory>
#include <string>
#include <thread>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#ifdef _WIN32
typedef int socklen_t;
#else
typedef int SOCKET;
#endif

class TcpEchoSession : public std::enable_shared_from_this<TcpEchoSession> {
public:
    TcpEchoSession(SOCKET socket_fd)
    : socket_fd_(socket_fd)
    , stop_echoing_(false)
    {
    }

    ~TcpEchoSession()
    {
#ifdef _WIN32
        closesocket(socket_fd_);
#else
        close(socket_fd_);
#endif
    }

    void run()
    {
        while (!stop_echoing_) {
            do_echo();
        }
    }

    void prepare_stop()
    {
        stop_echoing_ = true;
    }

private:
    void do_echo()
    {
        auto self(shared_from_this());
        char buffer[max_length] = {0};
        int n = recv(socket_fd_, buffer, max_length, 0);
        if (n > 0) {
            send(socket_fd_, buffer, n, 0);
        }
    }

    static const int max_length = 256;
    SOCKET socket_fd_;
    bool stop_echoing_;
};

class TcpEchoServer
{
public:
    TcpEchoServer()
    : listening_fd_(-1)
    {
    }

    ~TcpEchoServer()
    {
    }

    int start()
    {
        return start_server_session();
    }

    void prepare_stop()
    {
        session_->prepare_stop();
    }

    void stop()
    {
        close_server_session();
    }

    int get_server_port()
    {
        struct sockaddr_in assigned_address;
        socklen_t len = sizeof(assigned_address);
        if (getsockname(listening_fd_, (struct sockaddr *)&assigned_address, &len) == -1) {
            return -1;
        }
        else {
            return ntohs(assigned_address.sin_port);
        }
    }

private:
    int start_server_session()
    {
#ifdef _WIN32
        WSADATA wsa_data;
        WSAStartup(MAKEWORD(2, 2), &wsa_data);
#endif
        listening_fd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (listening_fd_ == -1) {
            return -1;
        }
        struct sockaddr_in server_address;
        std::memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_address.sin_port = htons(0);

        if (bind(listening_fd_, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
            return -1;
        }
        if (listen(listening_fd_, 1) != 0) {
            return -1;
        }
        server_thread_ = std::thread(&TcpEchoServer::handle_client, this);
        return 0;
    }

    void close_server_session()
    {
        server_thread_.join();
        session_.reset();

#ifdef _WIN32
        closesocket(listening_fd_);
        WSACleanup();
#else
        close(listening_fd_);
#endif
    }

    void handle_client()
    {
        SOCKET client_fd = accept(listening_fd_, NULL, NULL);
        if (client_fd != -1) {
            session_ = std::make_shared<TcpEchoSession>(client_fd);
            session_->run();
        }
    }

    SOCKET listening_fd_;
    std::thread server_thread_;
    std::shared_ptr<TcpEchoSession> session_;
};
