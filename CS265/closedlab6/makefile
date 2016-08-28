OBJSa = closedlab6a.o Queue.o
OBJSb = closedlab6b.o Queue.o stack.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab6a : $(OBJSa)
	$(CC) $(LFLAGS) $(OBJSa) -o closedlab6a.out

closedlab6b : $(OBJSb)
	$(CC) $(LFLAGS) $(OBJSb) -o closedlab6b.out

closedlab6a.o : closedlab6a.cpp Queue.h
	$(CC) $(CFLAGS) closedlab6a.cpp

closedlab6b.o : closedlab6b.cpp Queue.h stack.h
	$(CC) $(CFLAGS) closedlab6b.cpp

Queue.o : Queue.cpp Queue.h
	$(CC) $(CFLAGS) Queue.cpp

stack.o : stack.cpp stack.h
	$(CC) $(CFLAGS) stack.cpp
