# Sphere Binary File

CFLAGS = -g -static -o3
SBF_CSOURCE = $(shell find src -name '*.c')

SBF_OBJ = $(patsubst src/%.c, bin/runtime.o, $(SBF_CSOURCE))
SBF_BIN = $(shell find bin -name '*.o')

SBF_GCC = $(shell gcc $(CFLAGS) $(SBF_OBJ))

run: rebuild
	clear
	chmod +x ./bin/runtime.o && ./bin/runtime.o

debug: rebuild
	chmod +x ./bin/runtime.o
	clear

build:
	clang $(SBF_CFLAGS) $(SBF_CSOURCE) -o bin/runtime.o
	
bin/src/%.o: src/%.c
	clang $(SBF_CFLAGS) $(SBF_CSOURCE) -o bin/runtime.o

clean:
	-rm -rf ./bin/*
	-rm ./bin./runtime.o
	clear

rebuild: clean build
	clear
