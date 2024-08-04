#include "FdQueue.h"

FdQueue::FdQueue()
:m_mutex()
,m_empty(m_mutex)
{

}

FdQueue::~FdQueue() {}

bool FdQueue::empty() {
    return m_fd_queue.size() == 0;
}

void FdQueue::push(int fd) {
    m_mutex.lock();
    m_fd_queue.push(fd);
    m_empty.signal();
    m_mutex.unlock();
}

int FdQueue::pop() {
    m_mutex.lock();
    while (empty() && m_flag) {
        m_empty.wait();
    }

    if (m_flag) {
        int fd = m_fd_queue.front();
        m_fd_queue.pop();
        m_mutex.unlock();
        return fd;
    }
    m_mutex.unlock();
}

void FdQueue::wakeup() {
    m_flag = false;
    m_empty.broadcast();
}