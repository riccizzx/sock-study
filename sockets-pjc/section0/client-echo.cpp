#include "prac.hpp"


int
s::cl::client()
{
	int err = 0;
	//const std::string msg;
	std::string msg;
	int send_data = 0;

	if (WSAStartup(MAKEWORD(2, 2), &c.ws) != 0) {
		handle_error("error!");
		return -1;
	};

	c.client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (c.client_sock == INVALID_SOCKET) {
		handle_error("error in socket!");
		return -1;
	}

	c.client.sin_family = AF_INET;
	c.client.sin_port = htons(port);

	err = connect(c.client_sock, (sockaddr*)&c.client, sizeof(c.client));
	if (err == SOCKET_ERROR) {
		handle_error("failed to connect in server!");
		return -1;
	}
	else {
		printf("connection establish!");
	}

	//c.buffer[MAX_BUFFER_SIZE];

	do {
		std::getline(std::cin, msg);
		
		send_data = send(c.client_sock, c.buffer, sizeof(c.buffer), 0);
		if (send_data > 0)
		{
			
		}
	} while (msg != "quit");

	return 0;
}