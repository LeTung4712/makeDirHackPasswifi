CFLAGS = -c -Wall
CC = gcc
LIBS = -lm

all: main

main: main.o 
	${CC} main.o fields.o -o main
	rm -f *.o

main.o: main.c
	${CC} ${CFLAGS} main.c fields.c
	 

clean:
	rm -f *.o *~ main
