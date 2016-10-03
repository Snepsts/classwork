OBJS = lab7.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab7 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab7.out

lab7.o : lab7.cpp math_set.h
	$(CC) $(CFLAGS) lab7.cpp
