OBJS = lab11.o csplit.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab11 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab11.out

lab11.o : lab11.cpp split.h Stack.h Queue.h
	$(CC) $(CFLAGS) lab11.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp
