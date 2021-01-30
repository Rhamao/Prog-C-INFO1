CC=gcc
CFLAGS=-Wall -ansi
DEPS=stack.h
OBJ=stack.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^
