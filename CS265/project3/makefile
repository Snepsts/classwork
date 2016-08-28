OBJS = project3.o queue.o inventory.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

project3 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o project3.out

project3.o : project3.cpp inventory.h queue.h
	$(CC) $(CFLAGS) project3.cpp

queue.o : queue.cpp queue.h
	$(CC) $(CFLAGS) queue.cpp

inventory.o : inventory.cpp inventory.h
	$(CC) $(CFLAGS) inventory.cpp
