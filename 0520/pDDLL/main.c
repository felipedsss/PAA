#include "main.h"
#include <stddef.h>
#include <stdio.h>
#define SUCESS 0
#define FAIL 1
void myprint(void *p) {
    
    printf("%d\n",*(int *)p );
    // TODO
}

int comparaDados(void *dado1, void *dado2) {
    //CONSIDERANDO INT
        if (dado1 == NULL || dado2 == NULL) {
        //printf("Erro: Ponteiros nulos recebidos\n");
        return FAIL; // ou outro valor que faça sentido para sua lógica
    }

    // Convertendo os ponteiros para inteiros e comparando os valores
    int valor_a = *(int *)dado1;
    int valor_b = *(int *)dado2;

    //printf("Comparando %d com %d\n", valor_a, valor_b);
    //printf ("\n %d \n", valor_a - valor_b);

        return valor_a - valor_b;
    
    // TODO
}





int main(int argc, char *argv[]) {
    int endFlag = 0;
    int novo;
    pDDLL lista = NULL;
    cDDLL(&lista, sizeof(int));
    
    //printf("TESTE");
    while (endFlag < 6) {
    if (!fscanf(stdin, "%d", &novo)) {
        // printf("FIM de leitura %d\n", novo);
        //printf ("(%d\n)", novo);
        break;
    }    
   //printf("{%d}", novo);
        if((iBegin(lista, &novo)) == SUCESS){
            //printf ("(%d\n)", novo);
        }
        else {
            printf("Erro na insercao\n");
        }
        endFlag++;
    }
    //printf("IMPRIMINDO TODOS OS ELEMENTOS");
    pAll(lista, myprint);
    //printf("IMPRIMINDO O MAIOR ELEMENTO");
    
    pMax(lista, comparaDados, myprint);
    // TODO
    
    return 0;
}
