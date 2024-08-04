#include "Acceptor.h"
#include <sys/types.h>
#include <sys/socket.h>

Acceptor::Acceptor(const string& ip, unsigned short port)
:m_addr(ip, port)
{
    ready();
}

Acceptor::~Acceptor() {}

void Acceptor::ready() {
    m_fd = socket(AF_INET, SOCK_STREAM, 0);

    int reuseAddr = 1;
    setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &reuseAddr, sizeof(int));

    int reusePort = 1;
    setsockopt(m_fd, SOL_SOCKET, SO_REUSEPORT, &reuseAddr, sizeof(int));

    bind(m_fd, (struct sockaddr*)m_addr.getAddr(), sizeof(struct sockaddr));

    listen(m_fd, 128);
}

int Acceptor::accept() {
    int fileDescriptor = ::accept(m_fd, nullptr, nullptr);
    return fileDescriptor;
}

int Acceptor::getFileDescriptor() {
    return m_fd;
}