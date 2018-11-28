#! /bin/bash

g++ -std=c++11 -gdwarf-2 -g3 -O0 -fno-builtin shared.cpp -fPIC -shared -Wl,-soname,libshared.so.$1 -o libshared.so.$1.0
ln -sfT libshared.so.$1.0 libshared.so.$1
