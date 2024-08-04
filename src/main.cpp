#include <iostream>
#include "Server.h"

using namespace std;

int main(int argc, char* argv[])
{
    Server server("0.0.0.0", 8888, 4);
    server.start();
    return 0;
}