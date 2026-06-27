FLAGS=-03
CC=gcc

allprimos: main.o primos.o
	gcc -o allprimos main.o primos.o

main.o: main.c primes.h
	gcc -o main.o main.c -c
primos.o: primes.c primes.h
	gcc -o primos.o primes.c -c
clean:
	rm -rf *.o


