@echo off
setlocal

REM Definir variáveis
set CC=..\..\..\mingw64\bin\gcc.exe
set CFLAGS=-Wall -Wextra -pedantic -std=c11 -g

REM Compilar pDDLL.o a partir de pDDLL.c e seus headers
%CC% %CFLAGS% -c pDDLL.c -o pDDLL.o

REM Compilar DDLL.o a partir de DDLL.c e seus headers
%CC% %CFLAGS% -c DDLL.c -o DDLL.o

REM Compilar o executável main
%CC% %CFLAGS% -o main.exe main.c pDDLL.o DDLL.o

REM Echo a mensagem de compilação bem-sucedida
echo Compilation complete.

.\main.exe
endlocal