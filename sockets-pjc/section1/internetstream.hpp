#ifndef SECTION1_HEADER_HPP
#define SECTION1_HEADER_HPP

#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

struct var {
    int sock, errnum, h_addr_index;
    struct sockaddr_in6 server;
    struct hostent* hp;
    char buf[1024];
}v;

/**
* 
 * This program creates a socket and initiates a connection with
 * the socket given in the command line. Some data are sent over the
 * connection and then the socket is closed, ending the connection.
 * The form of the command line is: streamwrite hostname portnumber

 **/

#endif