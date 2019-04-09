// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex2
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h> 

void DumpHex(void* pData, int byteLen);

int main(int argc, char **argv) {
  char     charVal = '0';
  int32_t  intVal = 1;
  float    floatVal = 1.0;
  double   doubleVal  = 1.0;

  typedef struct { 
    char     charVal;
    int32_t  intVal;
    float    floatVal;
    double   doubleVal;
  } Ex2Struct;
  Ex2Struct structVal = { '0', 1, 1.0, 1.0 };

  DumpHex(&charVal, sizeof(char));
  DumpHex(&intVal, sizeof(int32_t));
  DumpHex(&floatVal, sizeof(float));
  DumpHex(&doubleVal, sizeof(double));
  DumpHex(&structVal, sizeof(structVal));

  return EXIT_SUCCESS;
}

void DumpHex(void* pData, int byteLen) {	
	// print length of data and address of ptr
	printf("The %d bytes starting at %p are:", byteLen, pData);
	// print out the data as bytes from pData by byteLen length
	for (int i = 0; i < byteLen; i++) {
		uint8_t one_byte = *(uint8_t*)(pData + i);
		printf(" %02" PRIx8, one_byte);
	}
	printf("\n");
}
