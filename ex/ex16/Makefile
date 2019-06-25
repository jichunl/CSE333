# Copyright [2019] <Jichun Li> [copyright]
# CSE 333  Spring 2019
# ex16
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11

# defalut make
all: ex16
	
ex16: ex16.o listen.o
	$(CC) $(CPP_FLAGS) -o $@ $^
ex16.o: ex16.cc listen.h
	$(CC) $(CPP_FLAGS) -c $<
listen.o: listen.cc listen.h
	$(CC) $(CPP_FLAGS) -c $<
# clean executable and others
clean:
	rm -rf ex16 *.o *~ ex16.dSYM
