#include "internetstream.hpp"

int main(){
	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws) != 0) {
		std::cerr << "failed!";
	}
	v.sock = socket(AF_INET, SOCK_STREAM, 0);
	if (v.sock == INVALID_SOCKET){
		std::cerr << "error!" ;
	}



}