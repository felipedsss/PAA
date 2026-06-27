CC=..\..\..\..\..\mingw64\bin\gcc.exe
CFLAGS=-Wall -Wextra -pedantic -std=c11 

# Target principal
all: main

# Compilar o executável myApp
main: main.c BST.o
	$(CC) $(CFLAGS) -o main main.c BST.o

# Compilar BST.o a partir de BST.c e seus headers
BST.o: BST.c BST_pri.h BST_pub.h
	$(CC) $(CFLAGS) -c BST.c

# Limpar arquivos objetos e executável
clean:
	del -f main.exe *.o
