gcc -E sortc.c -o sortc.i
gcc -S sortc.c
gcc -c sortc.c
gcc -o sortc sortc.c
valgrind --leak-check=full --show-leak-kinds=all ./sortc
