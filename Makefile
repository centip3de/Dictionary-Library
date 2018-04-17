CC = gcc
CCFLAGS = -Wall 

%.o: %.c
	$(CC) -c $(CCFLAGS) $<

all: cdictlib

cdictlib: cdictlib.o
	$(CC) -o $@ cdictlib.o

main: main.o cdictlib.o
	$(CC) -o $@ main.o cdictlib.o

clean: 
	$(RM) *.o *.gch *.swp .DS_Store main 