// SECTION 0 STUDYING LOW LEVEL SOCKETS IN C++
// doc https://docs.oracle.com/cd/E26502_01/html/E35299/sockets-18552.html#scrolltoc
#pragma once
#include "..\sockets-pjc.h"

#ifndef SOCKET_SECTION0_HPP
#define SOCKET_SECTION0_HPP

#define PORT 9909

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

// simple explanation of sockets functionality in c++

#pragma comment(lib, "ws2_32.lib")

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while(0)

namespace s {

	class so {

	public:

		int main();

	};
}

#endif