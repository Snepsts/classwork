OBJS = closedlab9.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab9 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab9.out

closedlab9.o : closedlab9.cpp
	$(CC) $(CFLAGS) closedlab9.cpp
