
.PHONY: all
all: abidiff

.PHONY: abidiff
abidiff: libtest-v0.so libtest-v1.so
	abidiff libtest-v0.so libtest-v1.so

libtest-v0.so: test-v0.cc
	g++ -g -Wall -shared -o libtest-v0.so test-v0.cc

libtest-v1.so: test-v1.cc
	g++ -g -Wall -shared -o libtest-v1.so test-v1.cc
