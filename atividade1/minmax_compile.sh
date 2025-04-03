gcc -E minmax.c -o minmax.i
gcc -S minmax.c
gcc -c minmax.c
gcc -o minmax minmax.c
valgrind --leak-check=full -show-leak-kinds=all ./minmax
