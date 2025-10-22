#include "prac.hpp"


int
s::cl::client()
{
	int err = 0;
	if (WSAStartup(MAKEWORD(2, 2), &c.ws) != 0) {
		handle_error("error!");
		return - 1;
	};

	c.client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (c.client_sock == INVALID_SOCKET) {
		handle_error("error in socket!");
		return -1;
	}


}