CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -g

# Target principal
all: main

# Target para compilar com informações de depuração

debug: main

# Compilar o executável myApp
main: main.c PDDLL.o DDLL.o main.h
	$(CC) $(CFLAGS) -o main main.c PDDLL.o DDLL.o

# Compilar pDDLL.o a partir de pDDLL.c e seus headers
pDDLL.o: PDDLL.c PDDLL_pri.h PDDLL_pub.h
	$(CC) $(CFLAGS) -c PDDLL.c

DDLL.o: DDLL.c DDLL_pri.h DDLL_pub.h
	$(CC) $(CFLAGS) -c DDLL.c

# Limpar arquivos objetos e executável
clean:
	rm -f main *.o
