all: generic_data 
 
generic_data: main.o generic_functions.o
	gcc -o generic_data main.o
 
main.o: main.c generic_functions.h
	gcc -o main.o main.c generic_functions.h
 
generic_functions.o: generic_functions.c generic_functions.h
	gcc -o generic_functions.o generic_functions.c generic_functions.h
 
clean:
	rm -rf *.o *~ printy
