OBJS = complexType.o project1.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

project1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o project1.out

project1.o : project1.cpp complexType.h
	$(CC) $(CFLAGS) project1.cpp

complexType.o : complexType.cpp complexType.h
	$(CC) $(CFLAGS) complexType.cpp
