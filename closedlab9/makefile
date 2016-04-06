OBJS = main.o class.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

object : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o object.out

main.o : main.cpp (all included header files)
	$(CC) $(CFLAGS) main.cpp

class.o : class.cpp class.h
	$(CC) $(CLFAGS) class.cpp
