#include "Condition.h"

Condition::Condition(MutexLock& mutex)
:m_mutex(mutex)
{
    pthread_cond_init(&m_cond, nullptr);
}

Condition::~Condition() {
    pthread_cond_destroy(&m_cond);
}

void Condition::wait() {
    pthread_cond_wait(&m_cond, m_mutex.getMutexLockPtr());
}

void Condition::signal() {
    pthread_cond_signal(&m_cond);
}

void Condition::broadcast() {
    pthread_cond_broadcast(&m_cond);
}