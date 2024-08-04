#pragma once

#include <pthread.h>

class MutexLock {
public:
    MutexLock();
    ~MutexLock();

    //上锁
    void lock();
    //尝试上锁
    void tryLock();
    //解锁
    void unlock();

    pthread_mutex_t *getMutexLockPtr();
private:
    pthread_mutex_t m_mutex;

};
