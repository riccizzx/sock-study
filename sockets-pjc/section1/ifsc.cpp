#include "internetstream.hpp"

int var::struc::run(){

	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
		std::cerr << "failed!";
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sock == INVALID_SOCKET){
		std::cerr << "error!" ;
	}


	char host[NI_MAXHOST];
	char service[NI_MAXSERV];
	
	server.sin6_family = AF_INET6;
	server.sin6_port = htons(port);
	inet_pton(AF_INET, "0.0.0.0", &server.sin6_addr);

	
	
}