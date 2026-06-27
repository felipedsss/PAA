@echo off
setlocal

REM Definir variáveis
set CC=..\..\..\..\mingw64\bin\gcc.exe
set CFLAGS=-Wall -Wextra -pedantic -std=c11 -g

REM Compilar pDDLL.o a partir de pDDLL.c e seus headers
%CC% %CFLAGS% -c BST.c -o BST.o

REM Compilar DDLL.o a partir de DDLL.c e seus headers
%CC% %CFLAGS% -c DDLL.c -o DDLL.o

REM Compilar QDBST.o a partir de QDBST.c e seus headers
%CC% %CFLAGS% -c QDBST.c -o QDBST.o

REM Compilar o executável main
%CC% %CFLAGS% -o main main.c QDBST.o BST.o DDLL.o

REM Echo a mensagem de compilação bem-sucedida
echo Compilation complete.

.\main.exe < QDBST.in
endlocal

