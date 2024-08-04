#include "MutexLock.h"

#include "MutexLock.h"
#include <stdio.h>

MutexLock::MutexLock()
{
    int ret = pthread_mutex_init(&m_mutex, nullptr);
    if(ret)
    {
        perror("pthread_mutex_init");
        return;
    }
}

MutexLock::~MutexLock()
{
    int ret = pthread_mutex_destroy(&m_mutex);
    if(ret)
    {
        perror("pthread_mutex_destroy");
        return;
    }
}

//上锁
void MutexLock::lock()
{
    int ret = pthread_mutex_lock(&m_mutex);
    if(ret)
    {
        perror("pthread_mutex_lock");
        return;
    }
}
//尝试上锁
void MutexLock::tryLock()
{
    int ret = pthread_mutex_trylock(&m_mutex);
    if(ret)
    {
        perror("pthread_mutex_trylock");
        return;
    }
}
//解锁
void MutexLock::unlock()
{
    int ret = pthread_mutex_unlock(&m_mutex);
    if(ret)
    {
        perror("pthread_mutex_unlock");
        return;
    }
}

pthread_mutex_t* MutexLock::getMutexLockPtr()
{
    return &m_mutex;
}