// Write a function that:
// Accepts an array of 32‐bit unsigned integers and a length
// Reverses the elements of the array in place
// Returns nothing (void)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define LENGTH 32

void extra_ex_1(int* arr);
void print(int* arr);

int main() {
	int arr[LENGTH];
	srand(time(NULL));
	for (int i = 0; i < LENGTH; i++) {
		arr[i] = rand() % LENGTH;
	}
	print(arr);
	extra_ex_1(arr);
	print(arr);
}

void extra_ex_1(int* arr) {
	int temp;
	for (int i = 0; i < LENGTH / 2; i++) {
		temp = arr[i];
		arr[i] = arr[LENGTH - 1 - i];
		arr[LENGTH - i - 1] = temp;
	}
}

void print(int* arr) {
	for (int i = 0; i < LENGTH; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
