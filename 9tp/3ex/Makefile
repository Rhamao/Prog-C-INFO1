CC = gcc
CFLAGS = -g -Wall -ansi
DEPS = char2d_array.h
OBJ = char2d_array.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^