#pragma once

#include "MutexLock.h"

class Condition {
    public:
        Condition(MutexLock& mutex);
        ~Condition();

        void wait();
        void signal();
        void broadcast();
    private:
        pthread_cond_t m_cond;
        MutexLock& m_mutex;
};