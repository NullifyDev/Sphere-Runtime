# Sphere Binary File

CFLAGS = -std=c23 -ffp-contract=fast -ffast-math -g -Wall -pedantic -Werror -Wextra
CSOURCE = $(shell find src/sbf src/runtime -name '*.c')

OBJ = $(patsubst src/%.c, bin/runtime.o, $(CSOURCE))
BIN = $(shell find bin -name '*.o')

GCC = $(shell gcc $(CFLAGS) $(OBJ))

run: rebuild
	clear
	chmod +x ./bin/runtime.o && ./bin/runtime.o

debug: rebuild
	chmod +x ./bin/runtime.o
	clear

build:
	clang $(CFLAGS) $(CSOURCE) -o bin/runtime.o
	
bin/src/%.o: src/%.c
	clang $(CFLAGS) $(CSOURCE) -o bin/runtime.o

clean:
	-rm -rf ./bin/*
	-rm ./bin./runtime.o
	clear

rebuild: clean build
	clear

riscv:
	