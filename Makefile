CC = gcc
CCFLAGS = -Wall 

%.o: src/%.c
	$(CC) -c $(CCFLAGS) $<

all: cdictlib

example: main

cdictlib: cdictlib.o
	$(CC) -o $@ cdictlib.o

main: main.o cdictlib.o
	$(CC) -o $@ main.o cdictlib.o

clean: 
	$(RM) *.o *.gch *.swp .DS_Store main 