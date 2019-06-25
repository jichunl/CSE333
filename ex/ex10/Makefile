# Copyright [2019] <Jichun Li> [copyright]
# CSE 333 Spring 2019
# ex10
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11

all: ex10

ex9: ex10.o Vector.o
	$(CC) $(CPP_FLAGS) -o $@ $^

ex9.o: ex10.cc Vector.h
	$(CC) $(CPP_FLAGS) -c $<

IntPair.o: Vector.cc Vector.h
	$(CC) $(CPP_FLAGS) -c $<

clean:
	rm -rf ex10 *.o *~ ex10.dSYMi

