#include "ThreadPool.h"
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>

WorkThread::WorkThread(ThreadPool& threadPool)
:m_thread_pool(threadPool)
{

}

WorkThread::~WorkThread() {}

void WorkThread::run() {
    int fd = m_thread_pool.getFd();
    char buffer[100];
    recv(fd, buffer, 10, MSG_WAITALL | MSG_NOSIGNAL);
    cout << buffer << endl;
    close(fd);
}

ThreadPool::ThreadPool(int size)
:m_size(size)
,m_is_exit(false)
{

}

ThreadPool::~ThreadPool() {}

void ThreadPool::start() {
    for (int i = 0; i < m_size; i++) {
        Thread* pThread = new WorkThread(*this);
        m_threads.push_back(pThread);
        pThread->start();
    }
}

void ThreadPool::stop() {
    while (!m_fd_queue.empty()) {
        sleep(1);
    }

    m_is_exit = true;

    m_fd_queue.wakeup();

    for (auto& thread : m_threads) {
        thread->stop();
    }
}

void ThreadPool::addFd(int fd) {
    m_fd_queue.push(fd);
}

int ThreadPool::getFd() {
    return m_fd_queue.pop();
}