
.PHONY: all
all: count exercise

count: count.cc
	g++ -g -o count -I/usr/include/dyninst count.cc -L/usr/lib64/dyninst -ldyninstAPI

exercise: ../exercise.cc
	g++ -g ../exercise.cc -o exercise
