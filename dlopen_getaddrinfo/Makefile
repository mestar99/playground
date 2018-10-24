
all:

static: main_static.c libA.c libA.h
	gcc -g libA.c main_static.c -pthread -o static

dynamic: libA.so main_dynamic.c
	gcc -g main_dynamic.c -ldl -o dynamic -Wl,-rpath -Wl,'$$ORIGIN'

libA.so: libA.c libA.h
#	gcc -shared -o libA.so -g libA.c -fPIC -pthread -lnss_files -lnss_dns -lresolv
	gcc -shared -o libA.so -g libA.c -fPIC -pthread

clean:
	rm libA.so static dynamic
