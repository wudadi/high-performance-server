#pragma once

#include "InetAddr.h"

class Acceptor {
    public:
        Acceptor(const string& ip, unsigned short port);
        ~Acceptor();
        void ready();
        int accept();
        int getFileDescriptor();
    private:
        InetAddr m_addr;
        int m_fd;
};