CC=gcc
CFLAGS=-Wall -ansi
DEPS=array.h
OBJ=array.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^
