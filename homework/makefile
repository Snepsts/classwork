OBJS = hw.o newstring.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

hw : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hw.out

hw.o : hw.cpp newstring.h
	$(CC) $(CFLAGS) hw.cpp

newstring.o : newstring.cpp newstring.h
	$(CC) $(CLFAGS) newstring.cpp
