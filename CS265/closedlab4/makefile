OBJS = CProduct.o closedlab4.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

closedlab4 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o closedlab4.out

closedlab4.o : closedlab4.cpp CProduct.h
	$(CC) $(CFLAGS) closedlab4.cpp

CProduct.o : CProduct.cpp CProduct.h
	$(CC) $(CFLAGS) CProduct.cpp
