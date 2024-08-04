#pragma once

#include "FdQueue.h"
#include "Thread.h"
#include <vector>

using namespace std;

class ThreadPool;

class WorkThread : public Thread {
    public:
        WorkThread(ThreadPool& threadPool);
        ~WorkThread();
        void run() override;
    private:
        ThreadPool& m_thread_pool;
};

class ThreadPool {
    public:
        ThreadPool(int size);
        ~ThreadPool();
        void start();
        void stop();
        int getFd();
        void addFd(int fd);
    private:
        int m_size;
        vector<Thread*> m_threads;
        FdQueue m_fd_queue;
        bool m_is_exit;
};