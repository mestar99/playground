
gcc 8.2.1
----------------

% make -B



gcc 4.9.2
---------------
% docker run -it --rm -v ${PWD}:/code-repo -w=/code-repo gcr.io/wg-blade/gcc-el7:4.9.2

% make -B

% ./a.out
Metadata
result: 123
No metadata

gcc 5.3.0
--------------
% docker run -it --rm -v ${PWD}:/code-repo -w=/code-repo gcr.io/wg-blade/gcc-el7:5.3.0

% make -B

% ./a.out
Metadata
result: 123
No metadata
