# Copyright [2019] <Jichun Li> [copyright]
# CSE 333 Spring 2019
# ex15
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11
PROG = ex15

all: $(PROG)
	
ex15: ex15.o connect.o
	$(CC) $(CPP_FLAGS) -o $@ $^

ex15.o: ex15.cc connect.h
	$(CC) $(CPP_FLAGS) -c $<

connect.o: connect.cc connect.h
	$(CC) $(CPP_FLAGS) -c $<

# clean executable and others
clean:
	rm -rf $(PROG) *.o *~ $(PROG).dSYM
