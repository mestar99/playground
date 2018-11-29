#all:
#	/opt/gcc-4.9.2/bin/g++ -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -o base_test 
#	/opt/ak-gcc-4.9.2/bin/g++ -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -o ak_test
#	/opt/bk-gcc-4.9.2/bin/g++ -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -o bk_test

# /opt/gcc-4.9.2/bin/g++ -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.1 -o libshared.so.1.0

.PHONY: all
all: test_4.8.5 test_4.9.2 test_5.3.1 test_6.3.1 test_7.3.1 test_native_4.9.2 test_native_5.3.0 test_native_6.3.0 test_hack_4.9.2 test_hack_5.3.0 test_hack_6.3.0 libshared.so.1 libshared.so.2 libshared.so.3 libshared.so.4 libshared.so.5 libshared.so.6 libshared.so.7 libshared.so.8 libshared.so.9 libshared.so.10 libshared.so.11

test_4.8.5: test.cpp
	./build_script.sh 4.8.5

test_4.9.2: test.cpp
	scl enable devtoolset-3 "./build_script.sh 4.9.2"

test_5.3.1: test.cpp
	scl enable devtoolset-4 "./build_script.sh 5.3.1"

test_6.3.1: test.cpp
	scl enable devtoolset-6 "./build_script.sh 6.3.1"

test_7.3.1: test.cpp
	scl enable devtoolset-7 "./build_script.sh 7.3.1"

test_native_4.9.2: test.cpp
	/opt/gcc-4.9.2/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_native_4.9.2

test_native_5.3.0: test.cpp
	/opt/gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_native_5.3.0

test_native_6.3.0: test.cpp
	/opt/gcc-6.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_native_6.3.0

test_hack_4.9.2: test.cpp
	/opt/hack-gcc-4.9.2/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_hack_4.9.2

test_hack_5.3.0: test.cpp
	/opt/hack-gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_hack_5.3.0

test_hack_6.3.0: test.cpp
	/opt/hack-gcc-6.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin test.cpp -ldl -o test_hack_6.3.0

# native 4.9.2
libshared.so.1: shared.cpp
	/opt/gcc-4.9.2/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.1 -o libshared.so.1.0
	ln -sfT libshared.so.1.0 libshared.so.1

# hack 5.3.0 newABI
libshared.so.2: shared.cpp
	/opt/hack-gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.2 -o libshared.so.2.0
	ln -sfT libshared.so.2.0 libshared.so.2

# hack 5.3.0 oldABI
libshared.so.3: shared.cpp
	/opt/hack-gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin -D_GLIBCXX_USE_CXX11_ABI=0 shared.cpp -fPIC -shared -Wl,-soname,libshared.so.3 -o libshared.so.3.0
	ln -sfT libshared.so.3.0 libshared.so.3

# native 5.3.0 newABI
libshared.so.4: shared.cpp
	/opt/gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.4 -o libshared.so.4.0
	ln -sfT libshared.so.4.0 libshared.so.4

# native 5.3.0 oldABI
libshared.so.5: shared.cpp
	/opt/gcc-5.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin -D_GLIBCXX_USE_CXX11_ABI=0 shared.cpp -fPIC -shared -Wl,-soname,libshared.so.5 -o libshared.so.5.0
	ln -sfT libshared.so.5.0 libshared.so.5

# native 6.3.0
libshared.so.6: shared.cpp
	/opt/gcc-6.3.0/bin/g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.6 -o libshared.so.6.0
	ln -sfT libshared.so.6.0 libshared.so.6

# 4.8.5
libshared.so.7: shared.cpp
	./build_shared.sh 7

# 4.9.2
libshared.so.8: shared.cpp
	scl enable devtoolset-3 "./build_shared.sh 8"

# 5.3.1
libshared.so.9: shared.cpp
	scl enable devtoolset-4 "./build_shared.sh 9"

# 6.3.1
libshared.so.10: shared.cpp
	scl enable devtoolset-6 "./build_shared.sh 10"

# 7.3.1
libshared.so.11: shared.cpp
	scl enable devtoolset-7 "./build_shared.sh 11"
