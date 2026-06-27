/*
 *Desenvolva um programa na Linguagem C que imprima os números primos de um determinado intervalo. O projeto deve ser constituído de código principal e a biblioteca 'primes'.
    Exemplos de entradas: 

        10 50
        1000 1010

      Como saída, espera-se a lista de números primos da faixa.
 *
 *
 *
 *
 *
 */

#include "primes.h"
#include <stdio.h>
int is_prime(int num) {
	if (num <= 0) return 0;
	if (num <= 3){
		return 1;
	}
	if (num==5) return 1;
	if (num % 2 == 0) return 0; //50% dos casos
	if (num % 3 == 0) return 0; //33.3% dos casos
	if (num % 5 == 0) return 0; //20% dos casos
	else {
		int i = 7;
		while (i<num/2 +1){
			if (num%i ==0) return 0; //7
			i = i+2;
			if (num%i ==0) return 0; //9
			i = i+2;
			if (num%i ==0) return 0; //1
			i = i+2;
			if (num%i ==0) return 0; //3
			i = i+4;
		}
	}
	return 1;
}

int next_prime(int current) {
	if (current <=0) {return 1;}
		else {
			if (current <=2) {return current+1;}
			else{
			int i=current;
			if (i%2 == 0) i--;
			i = i+2;
			if (is_prime(i) == 1)return i;
			while (is_prime(i) == 0  ){
				i=i+2;
				if (is_prime(i)) return i;
			}
		}
	}
}
