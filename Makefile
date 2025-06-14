CC ?= zig cc
LIB = lib
EXE = bin/lis

$(EXE): $(LIB)/mergesort.o $(LIB)/lis.o $(LIB)/array.o
	$(CC) -g -o $@ $^ -lm -g -fsanitize=address

$(LIB)/%.o: %.c
	$(CC) -g -c -o $@ $< -g -fsanitize=address

run:
	./$(EXE)

PHONY: run