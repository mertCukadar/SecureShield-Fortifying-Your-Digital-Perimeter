#include <Include/Port.h>


using namespace std;

#ifdef _WIN32

bool wsInit() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return false;
    }
    return true;
}

bool CreateSocket(SOCKET &sock, int type) {
    sock = socket(AF_INET, type, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Create socket failed.\n";
        return false;
    }
    closesocket(sock);
    WSACleanup();
    return true;
}



#endif
