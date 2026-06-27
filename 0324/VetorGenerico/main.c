#include <stdio.h>
#include "generic_functions.h"
int main(){
    struct GenericData *data;
    int *dataSize=0, teste;

    printf("Digite até 5 dados genéricos (inteiros, float ou string), um por linha:\n");

        readGenericData(data, dataSize);
        printf("Dados recebidos:");
        //printGenericData(data, *dataSize);
        
    
}