all: mainc

mainc: main.o pilha.o
	gcc main.c -c -W -Wall 



pilha.o: stack.c stack_pub.h stack_pri.o
	gcc -o pilha.o stack_pub.h

stack_pri.o: stack_pri.h
	gcc -o stack_pri.o stack_pri.h

clean:
	rm -rf *.o *~ mainc