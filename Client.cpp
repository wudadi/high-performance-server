#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8888);
	serverAddr.sin_addr.s_addr = inet_addr("106.55.227.123");

    connect(fd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));

    char buffer[] = "AAAAAAAAAA";
    send(fd, buffer, 10, 0);
    sleep(1);
    close(fd);
    return 0;
}