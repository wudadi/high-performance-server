#include "InetAddr.h"
#include <memory.h>

InetAddr::InetAddr(const string& ip, unsigned short port) {
    memset(&m_addr, 0 , sizeof(struct sockaddr_in));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    m_addr.sin_port = htons(port);
}

InetAddr::~InetAddr() {}

struct sockaddr_in* InetAddr::getAddr() {
    return &m_addr;
}