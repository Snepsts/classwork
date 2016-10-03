OBJS = lab6.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab6 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab6.out

lab6.o : lab6.cpp
	$(CC) $(CFLAGS) lab6.cpp
