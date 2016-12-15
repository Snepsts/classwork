OBJS = lab13.o csplit.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab13 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab13.out

lab13.o : lab13.cpp split.h
	$(CC) $(CFLAGS) lab13.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp
