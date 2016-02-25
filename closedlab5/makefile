OBJS = stack.o closedlab5.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab5 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab5.out

closedlab5.o : closedlab5.cpp stack.h
	$(CC) $(CFLAGS) closedlab5.cpp

stack.o : stack.cpp stack.h
	$(CC) $(CFLAGS) stack.cpp
