OBJS =  csplit.o split.o lab3.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab3 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab3.out

lab3.o : lab3.cpp split.h
	$(CC) $(CFLAGS) lab3.cpp

split.o : split.cpp split.h
	$(CC) $(CFLAGS) split.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp
