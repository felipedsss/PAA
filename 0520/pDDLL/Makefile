CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11 -g

# Target principal
all: main

# Target para compilar com informações de depuração

debug: main

# Compilar o executável myApp
main: main.c pDDLL.o DDLL.o
	$(CC) $(CFLAGS) -o main main.c pDDLL.o DDLL.o

# Compilar pDDLL.o a partir de pDDLL.c e seus headers
pDDLL.o: pDDLL.c PDDLL_pri.h pDDLL_pub.h
	$(CC) $(CFLAGS) -c pDDLL.c

DDLL.o: DDLL.c DDLL_pri.h DDLL_pub.h
	$(CC) $(CFLAGS) -c DDLL.c

# Limpar arquivos objetos e executável
clean:
	rm -f main *.o
