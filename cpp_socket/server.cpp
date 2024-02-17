/*
 * file  : server.cpp
 * author: vivek tripathi <vivek_tripathi@outlook.com>
 */

#include <iostream>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

class tcp_ipv4_socket
{
    private:
        int sock_fd;
	int port_number;
	std::string ip_str;
	struct sockaddr_in address;
    public:
	tcp_ipv4_socket(std::string ip, int port);
	virtual ~tcp_ipv4_socket();

	int get_sock_fd();
	int get_port_number();
	std::string get_ip_str();
	struct sockaddr_in get_sockaddr();
};


tcp_ipv4_socket::tcp_ipv4_socket (std::string ip, int port) : ip_str (ip), port_number (port)
{
    std::cout << "constructor" << std::endl;
    sock_fd = socket (AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        throw "socket";
    }

    int sock_opt = 1;
    int status = setsockopt (sock_fd, SOL_SOCKET, SO_REUSEADDR, &sock_opt, sizeof (sock_opt));
    if (status < 0)
    {
        throw "setsockopt";
    }

    address.sin_family = AF_INET;
    address.sin_port = htons (port_number);

    status = inet_pton (AF_INET, ip_str.c_str(), &(address.sin_addr.s_addr));
    if (status <= 0)
    {
        throw "inet_pton";
    }

    status = bind (sock_fd, (struct sockaddr*) &address, sizeof (struct sockaddr_in));
    if (status < 0)
    {
        throw "bind";
    }
}

tcp_ipv4_socket::~tcp_ipv4_socket ()
{
    std::cout << "destructor" << std::endl;
    if (sock_fd > 0)
    {
        std::cout << "cleaning up..." << std::endl;
        close (sock_fd);
    }
}

int tcp_ipv4_socket::get_sock_fd ()
{
    return sock_fd;
}

int tcp_ipv4_socket::get_port_number ()
{
    return port_number;
}

std::string tcp_ipv4_socket::get_ip_str ()
{
    return ip_str;
}

struct sockaddr_in tcp_ipv4_socket::get_sockaddr ()
{
    return address;
}


int main (int argc, char **argv)
{
    try
    {
        tcp_ipv4_socket server = tcp_ipv4_socket ("127.0.0.1", 8181);

        std::cout << "socket fd:: " << server.get_sock_fd() << std::endl;
        std::cout << "socket ip:: " << server.get_ip_str() << std::endl;
        std::cout << "socket port:: " << server.get_port_number() << std::endl;
    }
    catch (std::string &e)
    {
        std:: cout << e << std::endl;
    }

    return 0;
}
