//main,c gerado pelo usuário para testar as funções antes de mandar para ovpl
#include <stdio.h>
#include "libvet.h"

int main(){
    DynamicIntArray vec;
    initDynamicIntArray(&vec, 10);

    printf("Digite os elementos do vetor (digite -1 para finalizar):    \n");
    int entrada = 0;
    while (entrada != -1){
        printf("\nElemento: ");
        scanf("%d", &entrada);
        if (entrada!= -1){
            pushBack(&vec, entrada);
        }
    }
    for (int i=0; i< vec.size; i++){
        printf("%d ", vec.array[i]);
    }
    freeDynamicIntArray(&vec);

    return 0;

}
                    
