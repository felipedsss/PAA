nclude <stdio.h>
#include "primes.h"

int main() {
	    int first, last;
	        scanf("%d %d", &first, &last);
		    int count = 0; 
		        int current_prime = next_prime(first);
			    
			    printf("Numeros primos no intervalo de %d a %d\n", first, last);
			        while (current_prime < last) {
					        printf("%d ", current_prime);
						        current_prime = next_prime(current_prime);
							        count++;
								    }
				    printf("\n");
				        return 0;
}

