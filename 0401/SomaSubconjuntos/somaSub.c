#include <stdio.h>
#include "somaSub.h"

void somaSubconjuntosVoid(void *arr, int tamanhoElemento, int tamanhoTotal) {
    printf(" -- TAMANHO DO ELEMENTO %d ", tamanhoElemento);
    printf("TAMANHO TOTAL %d --", tamanhoTotal);
    //printf("1 %d ", *((int *)(arr)));
    //printf("2 %d ", *((int *)(arr + tamanhoElemento)));
    float somaFloat = 0.0;
    int somaInt = 0;
    int isFloat = 0;
    int nElementos = tamanhoTotal / tamanhoElemento;
    for (int i = 0; i <= tamanhoTotal; i++) {
        if (*((float *)(arr + i*tamanhoElemento)) < 0.000001){
            somaInt += *((int *)(arr + i*tamanhoElemento));;
            //printf("%d\n", somaInt);
            
            //printf("%d\n", *((int *)(arr + i*tamanhoElemento)));
        }
        else{
            isFloat = 1;
            somaFloat += *((float *)(arr + i*tamanhoElemento));
            //printf("%f\n", *((float *)(arr + i*tamanhoElemento)));
        }
            
        
        for (int j=i; j<nElementos-i; j++) {
        
       

            if (*((float *)(arr + j*tamanhoElemento)) < 0.000001){
                somaInt += *((int *)(arr + j*tamanhoElemento));;
                //printf("%d\n", somaInt);
                
                //printf("%d\n", *((int *)(arr + j*tamanhoElemento)));
            }
            else{
                isFloat = 1;
                somaFloat += *((float *)(arr + j*tamanhoElemento));
                //printf("%f\n", *((float *)(arr + j*tamanhoElemento)));
            }
            
        }
    }


    
    if (isFloat == 1){
        printf("%f ", somaFloat);
    } else {
        printf("%d ", somaInt);
    }
}


int main() {
    int vetorInt[3]={39, 25352, 0};
    float vetorFloat[3] = {16.545115, 89.301186, 0};
    somaSubconjuntosVoid(vetorInt, 4, 3);   
    somaSubconjuntosVoid(vetorFloat, 4, 3);

}

/*
######### Testes de Execução ########
Teste1: 1
Vetor Aleatório:52 Vetor Aleatório:36.984005 --
Teste2: 3
Vetor Aleatório:52 45 30 127
75
Vetor Aleatório:36.984005 94.161392 79.337837 210.483246
173.499237
--
######### FIM ########


*/