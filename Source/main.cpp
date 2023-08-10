#include "Include/Port.h"

int main() {
    if (wsInit()) {
        const char *programToRun = "your_program.exe"; // Change this to the program you want to run
        int result = system(programToRun);
        if (result == 0) {
            std::cout << "Program executed successfully." << std::endl;
        } else {
            std::cerr << "Error running program." << std::endl;
        }
    } else {
        std::cerr << "WSA initialization failed." << std::endl;
    }

    
        SOCKET sock;
        if (CreateSocket(sock, SOCK_STREAM, Port)) {
            std::cout << "Socket created and specified port closed." << std::endl;
        } else {
            std::cerr << "Error creating socket or binding." << std::endl;
        }
        CloseSocket(sock);

        // Run a program using the system function
        

    return 0;
}
