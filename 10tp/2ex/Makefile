CC = gcc
CFLAGS = -g -Wall -ansi
DEPS = list.h
OBJ = list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	gcc -o $@ $^