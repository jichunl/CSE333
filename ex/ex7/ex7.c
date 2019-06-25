// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex7
// jichunli@uw.edu 1531264

// This program accepts a directory name as a command-line argument and scans
// through the directory looking for filenames that end in the four characters
// ".txt" then prints out the ccontent of file to stdout

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024


// Accepts three parameters: stream, file_name, and message then prints out the
//      corresponding error message to the given stream with detailed
//      information
// Parameters:
//      FILE* stream: the stream that error message will be printed
//      char* file_name: the name of file that caused error
//      char* message: detailed information on the error
static void ErrorReport(FILE* stream, char* dir_name, char* message);

// Accepts two parameters: path_name, dir_name and concatenate 2 strings into
//    one, then prints the content of file with name dir_name in path with
//    name path_name
// Parameters:
//    char* path_name: the name of path that will be looked into
//    char* dir_name: the name of each file under path_name
static void FileAccess(char* path_name, char* dir_name);


// Accepts one parameters: full_path and the prints a out the content of given
//    txt file in that path to stdout
// Parameters:
//      char* full_path: full_path of the txt file that will be printed
static void PrintContent(char* full_path);

int main(int argc, char** argv) {
  if (argc != 2) {  // incorrect number of input argument
    ErrorReport(stderr, argv[1], "usage: ./ex7 input_dir");
  }

  DIR* dirp = opendir(argv[1]);
  if (dirp == NULL) {  // opendir failed
    ErrorReport(stderr, argv[1], "opendir failed");
  }

  struct dirent* entry;
  entry = readdir(dirp);
  char* dir_name;
  uint64_t dir_name_len;
  while (entry) {
    dir_name = entry->d_name;
    dir_name_len = strlen(dir_name);
    if (dir_name_len > 4U &&
        strcmp(".txt", dir_name + dir_name_len - 4U) == 0) {
        // The type of file is regular file, the length of name of file is
        //    greater than 4 and last 4 chars are .txt
        FileAccess(argv[1], dir_name);
    }
    entry = readdir(dirp);
  }

  closedir(dirp);
  return EXIT_SUCCESS;
}

void ErrorReport(FILE* stream, char* file_name, char* message) {
    fprintf(stream, "%s -- ", file_name);
    perror(message);
    exit(EXIT_FAILURE);
}

void FileAccess(char* path_name, char* dir_name) {
  // path_length includes length of path_name, dir_name. slash and EOF
  uint64_t path_length = strlen(path_name) + strlen(dir_name) + 2;
  char* full_path = (char*)malloc(sizeof(char) * path_length);
  if (full_path == NULL) {  // out of memory
     ErrorReport(stderr, path_name, "malloc failed");
  }
  snprintf(full_path, path_length, "%s/%s", path_name, dir_name);
  PrintContent(full_path);
  free(full_path);
}

void PrintContent(char* full_path) {
  int fd = open(full_path, O_RDONLY);
  if (fd == -1) {  // file open failed
    ErrorReport(stderr, full_path, "file open failed");
  }

  char buf[BUFSIZE];
  ssize_t len;
  do {
    len = read(fd, buf, BUFSIZE);
    if (len == -1) {
      if (errno != EINTR) {  // read failed
        close(fd);
        ErrorReport(stderr, full_path, "read error");
      }
      continue;
    }
    size_t total = 0;
    ssize_t wlen;
    while (total < len) {
      wlen = write(1, buf + total, len - total);
      if (wlen == -1) {
        if (errno != EINTR) {  // write failed
          close(fd);
          ErrorReport(stderr, full_path, "write error");
        }
        continue;
      }
      total += wlen;
    }
  } while (len > 0);

  close(fd);  // close file descriptor
}
