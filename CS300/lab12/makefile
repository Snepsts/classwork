BINS = lab12p1 lab12p2 lab12p3 lab12p4
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : $(BINS)

lab12p4 : lab12p4.o csplit.o
	$(CC) $(LFLAGS) lab12p4.o csplit.o -o lab12p4.out

lab12p4.o : lab12p4.cpp split.h
	$(CC) $(CFLAGS) lab12p4.cpp

csplit.o : csplit.cpp split.h
	$(CC) $(CFLAGS) csplit.cpp

lab12p3: lab12p3.cpp
	$(CC) $(LFLAGS) lab12p3.cpp -o lab12p3.out

lab12p2 : lab12p2.cpp
	$(CC) $(LFLAGS) lab12p2.cpp -o lab12p2.out

lab12p1 : lab12p1.cpp
	$(CC) $(LFLAGS) lab12p1.cpp -o lab12p1.out
