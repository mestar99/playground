
.PHONY: all
all: static_init double_init

static_init: main.o libLib.so
	g++ -o static_init main.o -L. -lLib

double_init: main.o libLib.so lib.o
	g++ -o double_init main.o -L. -lLib lib.o

main.o: main.cpp lib.hpp
	g++ -c -O0 -g3 -fno-inline -std=c++11 main.cpp -o main.o

libLib.so: lib.o
	g++ -shared -o libLib.so lib.o

lib.o: lib.cpp lib.hpp
	g++ -c -O0 -g3 -fno-inline -o lib.o -fPIC lib.cpp
