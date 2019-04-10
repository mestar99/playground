
.PHONY: all
all: main_reg main_part-lto main_lto

main_reg: main.o a.o_reg
	gcc main.o a.o_reg -o main_reg

main_part-lto: main.o a.o_lto
	gcc -flto main.o a.o_lto -o main_part-lto

main_lto: main.o_lto a.o_lto
	gcc -flto main.o_lto a.o_lto -o main_lto

main.o: main.c a.h
	gcc -g -O2 -c main.c -o main.o

main.o_lto: main.c a.h
	gcc -g -O2 -flto -c main.c -o main.o_lto

a.o_reg: a.c a.h
	gcc -g -O2 -c a.c -o a.o_reg

a.o_lto: a.c a.h
	gcc -g -O2 -flto -c a.c -o a.o_lto

.PHONY: clean
clean:
	rm -f main_reg main_part-lto main_lto a.o_reg a.o_lto main.o main.o_lto
