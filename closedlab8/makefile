OBJS = closedlab8.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab8 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab8.out

closedlab8.o : closedlab8.cpp listqueue.h containers.h
	$(CC) $(CFLAGS) closedlab8.cpp
