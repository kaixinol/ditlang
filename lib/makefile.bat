gcc -c split.c -o split.o
gcc -c  ./tinyexpr-flexible-array/expr_lib.c -o tinyexpr.o
ar rcs -o libexpansion.a split.o tinyexpr.o
