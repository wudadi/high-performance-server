#include "Server.h"
#include <sys/epoll.h>
#include <netinet/in.h>

Server::Server(const string& ip, unsigned short port, int threadNum)
:m_acceptor(ip, port)
,m_thread_pool(threadNum)
{
    m_thread_pool.start();
}

Server::~Server() {}

void Server::start() {
    int epollFileDes = epoll_create(1);

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = m_acceptor.getFileDescriptor();
    epoll_ctl(epollFileDes, EPOLL_CTL_ADD, m_acceptor.getFileDescriptor(), &ev);

    struct epoll_event evtList[1024];

    while (1) {
        int ret = epoll_wait(epollFileDes, evtList, 1024, -1);
        if (ret == -1) {
            // epoll_wait 失败
            perror("epoll_wait failed");
            // 根据 errno 进行错误处理
            switch (errno) {
                case EINTR:
                    printf("The epoll_wait call was interrupted by a signal.\n");
                    break;
                case EBADF:
                    printf("The epoll instance is invalid or closed.\n");
                    break;
                // 处理其他错误...
            }
            continue;
        }
        int newFileDes = m_acceptor.accept();
        m_thread_pool.addFd(newFileDes);
    }
}