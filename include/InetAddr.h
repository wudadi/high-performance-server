#pragma once

#include <arpa/inet.h>
#include <string>

using namespace std;

class InetAddr {
    public:
        InetAddr(const string& ip, unsigned short port);
        ~InetAddr();
        struct sockaddr_in* getAddr();
    private:
        struct sockaddr_in m_addr;
};