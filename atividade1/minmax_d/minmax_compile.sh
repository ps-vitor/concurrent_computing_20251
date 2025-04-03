gcc -E minmax.c -o minmax.i

gcc -S minmax.c
gcc -c minmax.c
gcc -o minmax minmax.c
