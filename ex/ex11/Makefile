# Copyright [2019] <Jichun Li> [copyright]
# CSE 333 Spring 2019
# ex11
# jichunli@uw.edu 1531264

CC = g++
CPP_FLAGS = -Wall -g -std=c++11
PROG = ex11

all: $(PROG)

$(PROG): $(PROG).o Vector.o
	$(CC) $(CPP_FLAGS) -o $@ $^

$(PROG).o: $(PROG).cc Vector.h
	$(CC) $(CPP_FLAGS) -c $<

Vector.o: Vector.cc Vector.h
	$(CC) $(CPP_FLAGS) -c $<

clean:
	rm -rf $(PROG) *.o *~ $(PROG).dSYMi

