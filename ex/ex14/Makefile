# Copyright [2019] <Jichun Li> [copyright]
# CSE 333 Spring 2019
# ex14
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11
PROG = ex14

all: $(PROG)
	
ex14: ex14.o Cartesian.o Polar.o
	$(CC) $(CPP_FLAGS) -o $@ $^

ex14.o: ex14.cc Coordinate.h Cartesian.h Polar.h
	$(CC) $(CPP_FLAGS) -c $<

Cartesian.o: Cartesian.cc Cartesian.h Coordinate.h
	$(CC) $(CPP_FLAGS) -c $<

Polar.o: Polar.cc Polar.h Coordinate.h
	$(CC) $(CPP_FLAGS) -c $<

# clean executable and others
clean:
	rm -rf $(PROG) *.o *~ $(PROG).dSYM
