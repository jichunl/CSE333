// CSE 333	Spring 2019
// ex0
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

double pi_calc (int64_t n);

int main(int argc, char* argv[]) {
	// check if argument count is valid 
	if (argc != 2) {
    	printf("ERROR: Only 2 arguments allowed\n");
		exit(EXIT_FAILURE);
    }

	const char* num_char = argv[1];

	// check if argument value is valid
	for (int i = 0; i < strlen(argv[1]); i++) {
		if (num_char[i] < 48 || num_char[i] > 57) {	// char is not a number
			printf("ERROR: Non-numerical char in 2nd argument\n");
			exit(EXIT_FAILURE);
		}
	}

    int64_t term = (int64_t)&argv[1];
	double pi = calc_pi(term);
    printf("Our estimate of Pi is %.20lf\n", pi);
}

double pi_calc (int64_t n) {
	double pi = 3;
	int64_t sign = -1;
    for (int64_t i = 1; i <= n; i++) {
		sign = sign * -1;
		pi = sign * 4 / (2 * n * 2 * (2 * n + 1) * (2 * n + 2)) + pi;
	}
	return pi;
}
