#pragma once

#include "MutexLock.h"
#include "Condition.h"
#include <queue>

using namespace std;

class FdQueue {
    public:
        FdQueue();
        ~FdQueue();
        bool empty();
        void push(int fd);
        int pop();
        void wakeup();
    private:
        queue<int> m_fd_queue;
        MutexLock m_mutex;
        Condition m_empty;
        bool m_flag;
};