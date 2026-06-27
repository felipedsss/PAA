#include <stdio.h>
#include "libvet.h"
int main (){
    int entrada;
    
    DynamicIntArray mainVec;
    initDynamicIntArray(&mainVec, 10);
    printf("Digite os elementos do vetor (digite -1 para finalizar): \n");
    while (entrada != -1){
        printf("Elemento: ");
        
        scanf("%d", &entrada);    
        pushBack(&mainVec, entrada);
    }
    for (size_t i=0; i<mainVec.size; i++){
        printf("%d ", mainVec.array[i]);
    }
    freeDynamicIntArray(&mainVec);
}