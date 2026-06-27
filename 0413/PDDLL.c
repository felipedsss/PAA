#include "PDDLL_pri.h"
#include <stdio.h>
#include <stdlib.h>

int pOdd(pDDLL p, void (*printodd)(void *p)) { //casting para um ponteiro genérico *p
    if (p == NULL || printodd == NULL) { // p não pode ser nulo, nem a função printodd que imprimirá os ponteiros, conforme o enunciado
        return FAIL;
    }

    NoDDLL *current = p->Begin; //inicializa-se o primeiro nó como sendo o início da lista p
    int index = 0; //indice inicial é igual a zero

    while (current != NULL) { //enquanto o nó atual for diferente de nulo
        if (index % 2 == 0) { // Se o índice for par
            printodd(current->dados); // Imprime o elemento
        }
        current = current->prox; //o nó atual passa a ser o próximo
        index++; //incrementamos o índice
    }

    return SUCESS;
}

int pSum(pDDLL p, int (*sumDDLL)(void *p1, void *p2), void (*printSum)(void *p)) {
    if (p == NULL || sumDDLL == NULL || printSum == NULL) { //necessário evitar: que o ponteiro da lista seja NULL, que a função que soma seja NULL e que a função que printa seja NULL
        return FAIL;
    }

    NoDDLL *current = p->Begin; //inicializa-se o primeiro nó como sendo o início da lista ps
    void *sum = NULL; // a soma começa como NULL

    while (current != NULL) { 
        if (sum == NULL) { // se a soma for NULL (situação inicial)
            sum = current->dados; // teremos que a soma são os dados do nó atual
        } else { // senão
            sum = sumDDLL(sum, current->dados); //a soma passa a ser o resultado da função soma dada no iniciado com os dados do nó atual
        }
        current = current->prox; //o nó atual passa a ser o próximo
    }

    printSum(sum);

    return SUCESS;
}