//  using select to verify if someone is trying to connect before the connetion is establish

#include <iostream>
#include <stdio.h>
#include <WS2tcpip.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define TRUE 1

#define h_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)

int
main() {

	SOCKET sock;
	int length;
	struct sockaddr_in6 server;
	int msgsock;
	char buffer[1024];
	int rval;
	fd_set ready;
	struct timeval to;


	// create socket
	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {

		h_error("cant initalize winsock api");
		return -1;
	}

	sock = socket(AF_INET6, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		
		h_error("cant create a socket");
		return -1;
	}

	server.sin6_family = AF_INET6;
	server.sin6_port = htons(9909);
	inet_pton(AF_INET, "127.0.0.1", &server.sin6_addr);

	if (bind(sock, (sockaddr*)&server, sizeof(server)) == -1) {
		
		h_error("cant bind the socket!");
		return -1;
	}

	listen(sock, SOMAXCONN);

	do{
		FD_ZERO(&ready);
		FD_SET(sock, &ready);
		to.tv_sec = 5;
		to.tv_usec = 0;

		if (select(sock + 1, &ready, 0, 0, &to) == -1) {

			h_error("select");
			continue;
		}

		if (FD_ISSET(sock, &ready)) {

			msgsock = accept(sock, (sockaddr*)0, (int*)0);
			if (msgsock == -1) {

				h_error("cant connect to the server");

			}

			else do {

				memset(buffer, 0, sizeof(buffer));
				if (rval = send(msgsock, buffer, sizeof(buffer), 0) == -1) {

					h_error("reading stream messages");
				}
				else if (rval == 0) {
					printf("ending connection");
				}
				else {
					printf("-->%s\n", buffer);
				}

			} while (rval > 0);
			closesocket(sock);
		}
		else {
			printf("Do something else\n");
		}
	
	} while (TRUE);

	return 0;
}