// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex16
// jichunli@uw.edu 1531264

// This is the header file for listen.cc

#ifndef _LISTEN_H_
#define _LISTEN_H_

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>

// bind() the socket to the address(es) and port.
// Tell the socket to listen() for incoming clients
int  Listen(char *portnum, int *sock_family);

// read() and write() to that connection.
void HandleClient(int c_fd, struct sockaddr *addr, size_t addrlen,
                  int sock_family);

#endif  // _LISTEN_H_
