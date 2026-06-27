nclude "sum_ascii.h"

int sum_ascii(const char *str) {
	    
	    int value, sum=0, count=0;
	    while (str[count]!='\0'){
			int value = str[count];
			sum = sum+value;
			count++;
							         
		}
		return sum;
}		    
		    // TODO
		    //     return sum;
		    //     }:
