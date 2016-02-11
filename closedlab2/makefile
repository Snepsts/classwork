OBJS = CheckADT.o closedlab2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab2 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab2.out

closedlab2.o : closedlab2.cpp CheckADT.h
	$(CC) $(CFLAGS) closedlab2.cpp

CheckADT.o : CheckADT.cpp CheckADT.h
	$(CC) $(CFLAGS) CheckADT.cpp
