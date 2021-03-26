CC = gcc
CFLAGS = -g -Wall -ansi
DEPS = int_array.h
OBJ = int_array.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^