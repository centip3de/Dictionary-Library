CC = gcc
CCFLAGS = -g -Wall -Werror
INCLUDE_FLAGS = -I include/

all: example

cdictlib.o: src/cdictlib.c
	$(CC) -c $(INCLUDE_FLAGS) $(CCFLAGS) $<

example.o: examples/example.c
	$(CC) -c $(INCLUDE_FLAGS) $(CCFLAGS) $<

cdictlib: cdictlib.o
	$(CC) -o $@ cdictlib.o

example: example.o cdictlib.o
	$(CC) -o $@ example.o cdictlib.o

clean: 
	$(RM) *.o *.gch *.swp .DS_Store example