.PHONY: all
all:
	gcc -Wall -Werror -o Main.bad Main.c /usr/lib64/libc.so.6 ./libWrap.so -ldl
	gcc -Wall -Werror -o Main.good Main.c ./libWrap.so -ldl
	gcc -g -O0 mallinfo.c -o mallinfo
