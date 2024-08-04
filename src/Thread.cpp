#include "Thread.h"

Thread::Thread()
:m_thread_id(0)
,m_is_running(false)
{

}

Thread::~Thread() {}

void Thread::start() {
    pthread_create(&m_thread_id, nullptr, threadFunc, this);
    m_is_running = true;
}

void Thread::stop() {
    if (m_is_running) {
        pthread_join(m_thread_id, nullptr);
        m_is_running = false;
    }
}

void* Thread::threadFunc(void* arg) {
    Thread* pThread = (Thread*)arg;
    pThread->run();
    pthread_exit(nullptr);
}