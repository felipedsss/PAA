all: mainc

mainc: main.o fila.o
	gcc -o fila main.o fila.o

main.o: main.c main.h
	gcc -o main.o main.c -c -W -Wall 

fila.o: queue.c queue_pub.h queue_pri.o
	gcc -o fila.o queue_pub.h queue_pri.o

queue_pri.o: queue_pri.h
	gcc -o queue_pri.o queue_pri.h

clean:
	rm -rf *.o *~ mainc


