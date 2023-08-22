CC = g++ -g -c -Wall -ansi -pedantic -std=c++20

LN = g++

OBJS = main.o

exe: $(OBJS)
	$(LN) -o exe $(OBJS)
 
main.o: main.cpp
	$(CC) main.cpp

clean:
	/bin/rm -f exe *.o *~ \#*
