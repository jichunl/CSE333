// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex15
// jichunli@uw.edu 1531264

// This C++ program The program should connect (via TCP) to the server on the
// supplied hostname and port, read the bytes from the local file, and it
// should write those bytes over the TCP connection. Close the TCP connection
// and exit when finish sending contents.

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include "./connect.h"
#define BUF 256
void Usage(char* progname);

int main(int argc, char **argv) {
  if (argc != 4) {
    Usage(argv[0]);
  }

  unsigned short port = 0;
  if (sscanf(argv[2], "%hu", &port) != 1) {
    Usage(argv[0]);
  }

  // Get an appropriate sockaddr structure.
  struct sockaddr_storage addr;
  size_t addrlen;
  if (!LookupName(argv[1], port, &addr, &addrlen)) {
    Usage(argv[0]);
  }

  // Connect to the remote host.
  int socket_fd;
  if (!Connect(addr, addrlen, &socket_fd)) {
    Usage(argv[0]);
  }

  // Read local file
  int file_fd = open(argv[3], O_RDONLY);
  if (file_fd == -1) {
    std::cerr << "open() " << argv[3] << " failed." << std::endl;
    Usage(argv[0]);
  }

  // Read something from the remote host.
  // Will only read BUF-1 characters at most.
  char readbuf[BUF];
  int res;
  while (1) {
    res = read(file_fd, readbuf, BUF-1);
    if (res == 0) {
      std::cerr << "socket closed prematurely" << std::endl;
      close(socket_fd);
      return EXIT_FAILURE;
    }
    if (res == -1) {
      if (errno == EINTR)
        continue;
      std::cerr << "socket read failure: " << strerror(errno) << std::endl;
      close(file_fd);
      close(socket_fd);
      return EXIT_FAILURE;
    }
    readbuf[res] = '\0';
    std::cout << readbuf;
    break;
  }

  // Write something to the remote host.
  while (1) {
    int wres = write(socket_fd, readbuf, res);
    if (wres == 0) {
      std::cerr << "socket closed prematurely" << std::endl;
      close(file_fd);
      close(socket_fd);
      return EXIT_FAILURE;
    }
    if (wres == -1) {
      if (errno == EINTR)
        continue;
      std::cerr << "socket write failure: " << strerror(errno) << std::endl;
      close(socket_fd);
      return EXIT_FAILURE;
    }
    break;
  }

  // Clean up.
  close(file_fd);
  close(socket_fd);
  return EXIT_SUCCESS;
}

void Usage(char* progname) {
  std::cerr << "usage: " << progname << " hostname port" << std::endl;
  exit(EXIT_FAILURE);
}
