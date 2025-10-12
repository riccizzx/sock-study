#include "prac.hpp"

// SIMPLE SERVER SIDE

void s::so::setup() {

	if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
		std::cerr << "error!" << std::endl;
	}
	else
	{
		std::cout << "Winsock initialized!" << std::endl;
	}

}

// AF_INET, SOCK_STREAM, IPROTO_TCP, exemple of a socket config

void s::so::soc(int family, int type, int protocol) {
	/*
	int choice;
	std::cin >> choice;
	
	// EXEMPLE OF A SWITCH STATEMENT TO CHOOSE THE FAMILY
	switch (choice) {

	case 1:
		family == AF_APPLETALK; // apple computer network protocol
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;
	
	case 2:
		family == AF_INET; // IPV4
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;

	case 3:
		family == AF_INET6; // IPV6
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;
	
	case 4:
		family == AF_IRDA; // infrared wireless
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;
	
	case 5:
		family == AF_UNIX; // UNIX file system
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
		break;

	default:
		break;
	}
	*/
	server_sock = socket(family, type, protocol); // create the socket

	memset(&server_addr, 0,sizeof(server_addr)); // clear the struct
	
	server_addr.sin_family = family;
	server_addr.sin_port = htons(PORT); // port
	
	// DIFERENT WAYS TO DEFINE THE IP ADRESS
	// 
	//server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip adress
	inet_pton(family, "0.0.0.0", &server_addr.sin_addr); // ip adress

}

void s::so::binder(sockaddr_in addres, int addres_size) {
	if (bind(server_sock, (sockaddr*)&addres, addres_size) == SOCKET_ERROR) {
		std::cerr << "Bind error!" << std::endl;
	}
	else
	{
		std::cout << "Binded!" << std::endl;
	}

	listen(server_sock, SOMAXCONN); // listen for connections
	// SOMAXCONN is the maximum number of connections, The length of the queue of 
	// pending connections may be limited by the maximum number the
	// underlying service provider supports.


}

void s::so::connec(SOCKET s, sockaddr_in addres, int addres_size)
{

	s = server_sock;
	addres = server_addr;
	addres_size = sizeof(addres);

	SOCKET so = accept(s, (sockaddr*)&addres, &addres_size);
	if (so == INVALID_SOCKET) {
		printf("Invalid socket!");
	}
	else {
		printf("Connected!");
	}
	

	// you can get addres from the connected socket with getnameinfo()
	char host[NI_MAXHOST];
	char service[NI_MAXSERV];
	memset(host, 0, NI_MAXHOST);
	memset(service, 0, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&addres, sizeof(addres),
		host, sizeof(host),
		service, sizeof(service), 0) ==0 ) {

		printf("%s connected on port %s\n", host, service);

	}
	else {
		inet_ntop(AF_INET, &addres.sin_addr, host, NI_MAXHOST);
		printf("%s connected on port %d\n", host, ntohs(addres.sin_port));
	}
}

void s::so::handlemsg() {


	
}

int s::so::run() {
	s::so server;


	server.setup();
	server.soc(AF_INET, SOCK_STREAM, 0);
	server.binder(server_addr, sizeof(server_addr));

		
	return 0;
}