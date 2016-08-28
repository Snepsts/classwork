OBJS = date.o closedlab3.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab3 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab3.out

closedlab3.o : closedlab3.cpp date.h
	$(CC) $(CFLAGS) closedlab3.cpp

date.o : date.cpp date.h
	$(CC) $(CFLAGS) date.cpp
