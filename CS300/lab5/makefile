OBJS =  csplit.o lab5.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab5 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab5.out

lab5.o : lab5.cpp split.h
	$(CC) $(CFLAGS) lab5.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp
