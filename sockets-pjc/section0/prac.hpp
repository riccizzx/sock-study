// SECTION 0 STUDYING LOW LEVEL SOCKETS IN C++
// doc https://docs.oracle.com/cd/E26502_01/html/E35299/sockets-18552.html#scrolltoc
#pragma once
#pragma comment(lib, "ws2_32.lib")
#include "..\sockets-pjc.h"

#ifndef SOCKET_SECTION0_HPP
#define SOCKET_SECTION0_HPP

#define PORT 9909
#define MAXDATASIZE 100

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

// simple explanation of sockets functionality in c++

namespace s {

	class so {

	public:

		void setup(); // func to set up socket

		void soc(int family, int type, int protocol);

		void binder(sockaddr_in addres, int addres_size);

		void connec(SOCKET s, sockaddr_in addres, int addres_size);

		void handlemsg();

	private:

		WSADATA ws; // wsadata object
		SOCKET server_sock;
		sockaddr_in server_addr;
	};
}

#endif