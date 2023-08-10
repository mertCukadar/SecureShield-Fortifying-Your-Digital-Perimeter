#ifndef PORT_H
#define PORT_H

#ifdef _WIN32
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

bool wsInit();
bool CloseSocket(SOCKET sock);
bool CreateSocket(SOCKET &sock, int type, int port);
extern int Port;

#endif

#endif // PORT_H
