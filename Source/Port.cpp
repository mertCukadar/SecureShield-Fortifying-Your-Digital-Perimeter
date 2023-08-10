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





#endif
