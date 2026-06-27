#include <stdio.h>
#include "generic_functions.h"

int main(){
	struct GenericData testData[5];
    
	int dataSize=0;
	printf("Digite até 5 dados genéricos (inteiros, float ou string), um por linha: )\n");
	int count= 0;
	while(count<5){
		readGenericData(&testData[count], &dataSize);
		count++;
	} 
	printGenericData(testData, dataSize);
}
