OBJS = driver.o Stack.o CharStack.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

project2 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o project2.out

driver.o : driver.cpp CharStack.h Stack.h
	$(CC) $(CFLAGS) driver.cpp

CharStack.o : CharStack.cpp CharStack.h Stack.h
	$(CC) $(CFLAGS) CharStack.cpp

Stack.o : Stack.cpp Stack.h
	$(CC) $(CFLAGS) Stack.cpp
