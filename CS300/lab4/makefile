OBJS =  csplit.o lab4.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab4 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab4.out

lab4.o : lab4.cpp split.h
	$(CC) $(CFLAGS) lab4.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp
