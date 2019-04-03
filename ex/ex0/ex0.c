// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex0
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

double pi_calc(int32_t n);

int main(int argc, char* argv[]) {
    // check if argument count is valid
    if (argc != 2) {
        printf("ERROR: Only 2 arguments allowed\n");
        exit(EXIT_FAILURE);
    }

    const char* num_char = argv[1];

    // check if argument value is valid
    while (*num_char != '\0') {
        if (*num_char < '0' || *num_char > '9') {   // char is not a number
            printf("ERROR: Non-numerical char in 2nd argument\n");
            exit(EXIT_FAILURE);
        }
        num_char++;
    }

    int32_t term = atoi(argv[1]);
    double pi = pi_calc(term);
    printf("Our estimate of Pi is %.20lf\n", pi);
    exit(EXIT_SUCCESS);
}

// Calculate pi value
double pi_calc(int32_t n) {
    double pi = 3;
    int32_t sign = -1;
    for (int32_t i = 1; i <= n; i++) {
        sign = sign * -1;
        pi = sign * 4.0 / ((2 * i) * (2 * i + 1) * (2 * i + 2)) + pi;
    }
    return pi;
}
