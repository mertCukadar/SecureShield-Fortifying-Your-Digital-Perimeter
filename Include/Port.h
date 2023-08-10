#ifndef PORT_H
#define PORT_H

#ifdef _WIN32
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#ifdef _WIN32

bool wsInit(); 

#endif

#endif

#endif // PORT_H    
