
all: libA.so
#	g++ -o a.out -g -std=c++11 main.cpp -ldl -Wl,-rpath -Wl,'$$ORIGIN' -L. -lA
	g++ -o a.out -g -std=c++11 main.cpp -ldl -Wl,-rpath -Wl,'$$ORIGIN'

libA.so: libA.cpp
	g++ -shared -o libA.so -g -std=c++11 libA.cpp -fPIC -pthread -lgrpc++
#	g++ -shared -o libA.so -g -I/opt/blade-third-party/gcp/include -std=c++11 libA.cpp -fPIC -pthread /opt/blade-third-party/gcp/lib/libGCP.a -lz
