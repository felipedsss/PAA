CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -g

all: main

main: main.c QDBST.o BST.o DDLL.o
	$(CC) $(CFLAGS) -o main main.c QDBST.o BST.o DDLL.o

QDBST.o: QDBST.c QDBST_pri.h QDBST_pub.h
	$(CC) $(CFLAGS) -c QDBST.c

BST.o: BST.c BST_pri.h BST_pub.h
	$(CC) $(CFLAGS) -c BST.c

DDLL.o: DDLL.c DDLL_pri.h DDLL_pub.h
	$(CC) $(CFLAGS) -c DDLL.c

clean:
	rm -f main *.o
