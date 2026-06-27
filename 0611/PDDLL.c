#include "PDDLL_pri.h"
#include <stdio.h>
#include <stdlib.h>

/*
Impressão dos Elementos dos Índices Pares da Lista: 
A função int pOdd(pDDLL p, void (*printodd)(void *p)) 
deve percorrer a lista e imprimir todos os elementos posicionados em 
índices pares usando uma função de impressão genérica fornecida pelo 
usuário. O parâmetro p é um ponteiro para a lista, enquanto printodd 
é um ponteiro para uma função que imprime um elemento da lista.
*/
int pOdd(pDDLL p, void (*printodd)(void *p)){
    if (p == NULL)
        return FAIL;
    NoDDLL *current = p->Begin;
    if (current == NULL)
        return FAIL;
    while (current != NULL){
        printodd(current->dados);
        current = current->prox;
        if (current == NULL)
            break;
        current = current->prox;
    }
    return SUCCESS;   
}

/*
Impressão da Soma dos Elementos da Lista: 
A função int pSum(pDDLL p, int (*sumDDLL)(void *p1, void *p2), void (*printSum)(void *p)) 
deve somar todos os elementos na lista usando 
uma função de comparação fornecida pelo usuário 
e imprimir suas informações usando uma função de 
impressão genérica também fornecida pelo usuário. 
O parâmetro p é um ponteiro para a lista, sumDDLL 
é um ponteiro para uma função que soma dois elementos 
da lista e, printSum é um ponteiro para uma função 
que imprime um elemento genérico passado como parâmetro.
*/
int pSum(pDDLL p, int (* sumDDLL)(void *p1, void *p2, void **sum), 
                                    void (*printSum)(void *p)) {
    if (p == NULL)
        return FAIL;
    NoDDLL *current = p->Begin;
    if (current == NULL)
        return FAIL;
    void *tempElementA = malloc(p->sizedata);
    void *tempElementB = malloc(p->sizedata);
    void **soma = malloc(p->sizedata);
    if (current->dados != NULL)
        memcpy(soma, current->dados, p->sizedata);
    current = current->prox;    
    while (current != NULL){
        if (current->dados != NULL)
            memcpy(tempElementA, current->dados, p->sizedata);
            memcpy(tempElementB, soma, p->sizedata);
            sumDDLL(tempElementA, tempElementB, soma);
        current = current->prox;
    }
    printSum(soma);
    free(tempElementA);
    free(soma);
    free(tempElementB);
    return SUCCESS;
}
