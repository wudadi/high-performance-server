#pragma once

#include "Acceptor.h"
#include "ThreadPool.h"

class Server {
    public:
        Server(const string& ip, unsigned short port, int threadNum);
        ~Server();
        void start();
        void stop();
    private:
        Acceptor m_acceptor;
        ThreadPool m_thread_pool;
};