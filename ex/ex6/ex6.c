// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex6
// jichunli@uw.edu 1531264

// This program accepts a file name as a single command-line argument, and it
// reads the file and then copies the file to stdout in reverse order, byte by
// byte.

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define READBUFSIZE 1   // size of read buffer

// Accepts three parameters: stream, file_name, and message then prints out the
//      corresponding error message to the given stream with detailed
//      information
// Parameters:
//      FILE* stream: the stream that error message will be printed
//      char* file_name: the name of file that caused error
//      char* message: detailed information on the error
void ErrorReport(FILE* stream, char* file_name, char* message);


int main(int argc, char** argv) {
    if (argc != 2) {
        ErrorReport(stderr, argv[1], "usage: ./ex6 infile");
    }

    FILE* fin_ptr = fopen(argv[1], "rb");
    if (fin_ptr == NULL) {
        ErrorReport(stderr, argv[1], "fopen for read failded");
    }

    if (fseek(fin_ptr, 0, SEEK_END) != 0) {
        ErrorReport(stderr, argv[1], "fseek for read failded");
    }

    int64_t size = ftell(fin_ptr);
    char readbuf[READBUFSIZE];

    for (int64_t i = size - 1; i >= 0; i--) {
        if (fseek(fin_ptr, i, SEEK_SET) != 0) {
            ErrorReport(stderr, argv[1], "fseek for read failed");
        }
        if (fread((void*)&readbuf, sizeof(char), READBUFSIZE, fin_ptr) !=
            sizeof(char)) {
            ErrorReport(stderr, argv[1], "fread buffer size mismatch");
        }
        printf("%c", readbuf[0]);
    }

    if (ferror(fin_ptr)) {
        ErrorReport(stderr, argv[1], "fread failed");
    }

    fclose(fin_ptr);
    return EXIT_SUCCESS;
}

void ErrorReport(FILE* stream, char* file_name, char* message) {
    fprintf(stream, "%s -- ", file_name);
    perror(message);
    exit(EXIT_FAILURE);
}

