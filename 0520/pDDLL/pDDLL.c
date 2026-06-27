#include "PDDLL_pri.h"
#include <stdio.h>
#include <stdlib.h>
#define SUCESS 0
#define FAIL 1

int pAll(pDDLL p, void (*printall)(void *p)){
    if (p == NULL )
        return FAIL;

    NoDDLL *current = p->Begin;

    if (current == NULL) {
        return FAIL;
    }
    printall(current->dados);
    while (current->prox != NULL) {
        
        current = current->prox;
        printall(current->dados);
    }    
    
    return SUCESS;   
}

int pMax(pDDLL p, int (* maxDDLL)(void *p1, void *p2), void (*printMax)(void *p)) {
    if (p == NULL)
        return FAIL;

    NoDDLL *current = p->Begin;

    if (current == NULL) {
        return FAIL;
    }

    void *max = current->dados;

    while (current != NULL) {
        if (maxDDLL(current->dados, max) > 0) {
            max = current->dados;
        }
        current = current->prox;
    }

    printMax(max);
    return SUCCESS;
}
