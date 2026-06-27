CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11

all: myApp

myApp: myApp.o mylib.o
	$(CC) $(CFLAGS) -o myApp myApp.o mylib.o

myApp.o: myApp.c myApp.h mylib_pub.h
	$(CC) $(CFLAGS) -c myApp.c

mylib.o: mylib.c mylib_pri.h mylib_pub.h
	$(CC) $(CFLAGS) -c mylib.c

clean:
	rm -f myApp *.o
