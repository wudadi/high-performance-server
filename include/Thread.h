#pragma once

#include <pthread.h>

class Thread {
    public:
        Thread();
        virtual ~Thread();
        void start();
        void stop();
        static void* threadFunc(void* arg);
        virtual void run() = 0;
    private:
        pthread_t m_thread_id;
        bool m_is_running;
};