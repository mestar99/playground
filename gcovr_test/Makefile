all:
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 example.cpp -o program

gcovr:
	gcovr --gcov-executable=/usr/bin/gcov -r . --html --html-details -o example-html-details.html

lcov:
	lcov --gcov-tool /usr/bin/gcov --directory . -b . --capture --no-external --output-file lcov.info
	genhtml -o lcov.html lcov.info
