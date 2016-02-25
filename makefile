OBJS = main.o class.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

object : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o object.out

main.o : main.o (all included header files)
	$(CC) $(CFLAGS) main.cpp

class.o : class.cpp class.h
	$(CC) $(CFLAGS) class.cpp

This is the basic copy and paste for my makefiles.
