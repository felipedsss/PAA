#/bin/bash

make clean
make
patchelf --set-interpreter ~/valgrtemp/glibc/pkg/glibc/usr/lib/ld-linux-x86-64.so.2 main 
valgrind ./main < QDBST.in --leak-check=full --show-leak-kinds=all --track-origin=yes -s