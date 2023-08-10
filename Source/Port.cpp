#include "Include/Port.h"

using namespace std;

#ifdef _WIN32

bool wsInit() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed.\n";
        return false;
    }
    return true;
}

bool CloseSocket(SOCKET sock) {
    if (closesocket(sock) != 0) {
        cerr << "Error closing socket." << endl;
        WSACleanup();
        return false;
    }
    WSACleanup();
    return true;
}

bool CreateSocket(SOCKET &sock, int type, int port) {
    sock = socket(AF_INET, type, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Create socket failed.\n";
        return false;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
        cerr << "Error binding socket." << endl;
        CloseSocket(sock);
        return false;
    }

    return true;
}

#endif
