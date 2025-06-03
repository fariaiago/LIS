CC ?= gcc
LIB = lib
EXE = bin/ordem

$(EXE): $(LIB)/mergesort.o $(LIB)/lis.o $(LIB)/array.o
	$(CC) -g -o $@ $^

$(LIB)/%.o: %.c
	$(CC) -g -c -o $@ $<

run:
	./$(EXE)

PHONY: run