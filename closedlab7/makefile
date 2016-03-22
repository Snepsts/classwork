OBJS = closedlab7.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab7 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab7.out

closedlab7.o : closedlab7.cpp triplet.h
	$(CC) $(CFLAGS) closedlab7.cpp
