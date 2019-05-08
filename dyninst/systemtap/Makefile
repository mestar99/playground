.PHONY: all
all: count_stap

.PHONY: count_stap
count_stap: exercise count.stp
	stap --dyninst -c exercise count.stp

exercise: ../exercise.cc
	g++ -g -o exercise ../exercise.cc
