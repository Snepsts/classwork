OBJS = lab15.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

lab15 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o lab15.out

lab15.o : lab15.cpp employee.h hourlyEmployee.h salariedEmployee.h
	$(CC) $(CFLAGS) lab15.cpp
