// SIMPLE_SERVER_APPLICATION
#include "prac.hpp"

int s::so::main() {

    WSADATA ws;
    SOCKET server_sock, client_sock;
    sockaddr_in server_addr{}, client_addr{};   
    char buffer[1024];
    int client_len = sizeof(client_addr);
    int recv_data = 0;

    // initialize winsock 
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
        std::cerr << "Error starting Winsock: " << WSAGetLastError() << "\n";
        return -1;
    }

    // create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == INVALID_SOCKET) {
        std::cerr << "Can't create socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return -1;
    }

    // bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << "\n";
        closesocket(server_sock);
        WSACleanup();
        return -1;
    }

    // listen
    if (listen(server_sock, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << "\n";
        closesocket(server_sock);
        WSACleanup();
        return -1;
    }

    std::cout << "Server listening on port " << PORT << "...\n";

    // accept connections
    while (true) {
        client_sock = accept(server_sock, (sockaddr*)&client_addr, &client_len);
        if (client_sock == INVALID_SOCKET) {
            std::cerr << "Accept failed: " << WSAGetLastError() << "\n";
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        std::cout << "Client connected: " << client_ip << "\n";

        // recv loop
        while (true) {
            memset(buffer, 0, sizeof(buffer));
            recv_data = recv(client_sock, buffer, sizeof(buffer) - 1, 0);

            if (recv_data > 0) {
                std::cout << "Received: " << buffer << "\n";
            }
            else if (recv_data == 0) {
                std::cout << "Client disconnected.\n";
                break;
            }
            else {
                std::cerr << "Recv error: " << WSAGetLastError() << "\n";
                break;
            }
        }

        closesocket(client_sock);
        std::cout << "Connection closed.\n";
    }

    closesocket(server_sock);
    WSACleanup();
    return 0;
}
