# Copyright [2019] <Jichun Li> [copyright]
# CSE 333 Spring 2019
# ex9
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11

all: ex9

ex9: ex9.o IntPair.o
	$(CC) $(CPP_FLAGS) -o $@ $^

ex9.o: ex9.cc IntPair.h
	$(CC) $(CPP_FLAGS) -c $<

IntPair.o: IntPair.cc IntPair.h
	$(CC) $(CPP_FLAGS) -c $<

clean:
	rm -rf ex9 *.o *~ ex9.dSYMi

