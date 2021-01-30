CC=gcc
CFLAGS=-Wall -ansi
DEPS=stack.h array.h
OBJ=stack.o array.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^
