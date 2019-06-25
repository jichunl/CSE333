// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex6
// jichunli@uw.edu 1531264

// This is the header file for the program that connects to the server

#ifndef _CONNECT_H_
#define _CONNECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

// Get an appropriate sockaddr structure
bool LookupName(char *name,
                unsigned short port,
                struct sockaddr_storage *ret_addr,
                size_t *ret_addrlen);

// Connect the socket to the remote host.
bool Connect(const struct sockaddr_storage &addr,
             const size_t &addrlen,
             int *ret_fd);

#endif  // _CONNECT_H_
