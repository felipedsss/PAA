#/bin/bash

make clean
make
patchelf --set-interpreter ~/valgtemp/glibc/pkg/glibc/usr/lib/ld-linux-x86-64.so.2 main 
valgrind ./main --leak-check=full --show-leak-kinds=all --track-origin=yes -s