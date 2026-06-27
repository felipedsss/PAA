#include "Stack_DDLL_pri.h"
#include "Stack_DDLL_pub.h"
#include "DDLL_pub.h"

int stack(ppStack pp, int sizedata){
    pDDLL lista = NULL;
    if(cDDLL(&lista, sizedata)){
        return FAIL;
    } else {
        Stack *p = (Stack*)malloc(sizeof(Stack));
        if (p == NULL) {
            dDDLL(&lista); // Limpa a DDLL em caso de falha na alocação da pilha
            return FAIL;
        }
        p->sizedata = sizedata;
        p->data = lista;
        p->size = 0; // Inicializa o tamanho da pilha como 0
        *pp = p;
        return SUCCESS;
    }
}

int unstack(ppStack pp){
    Stack *p = *pp;
    if (p == NULL) return FAIL;
    dDDLL((pDDLL*)&(p->data)); // Destrói a DDLL associada à pilha
    free(p); // Libera a memória alocada para a estrutura Stack
    *pp = NULL;
    return SUCCESS;
}

int push(pStack p, void *element){
    if (p == NULL || p->data == NULL || element == NULL) {
        return FAIL;
    }
    pDDLL lista = (pDDLL)(p->data);
    if (iBegin(lista, element) == SUCCESS) {
        p->size++; // Incrementa o tamanho da pilha após a inserção
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int pop(pStack p, void *element){
    if (p == NULL || p->data == NULL || element == NULL || p->size == 0) {
        return FAIL;
    }
    pDDLL lista = (pDDLL)(p->data);
    if (rBegin(lista, element) == SUCCESS) {
        p->size--; // Decrementa o tamanho da pilha após a remoção
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int cleanStack(pStack p){
    if (p == NULL || p->data == NULL) {
        return FAIL;
    }
    pDDLL lista = (pDDLL)(p->data);
    if (cleanDDLL(lista) == SUCCESS) {
        p->size = 0; // Redefine o tamanho da pilha como 0 após a limpeza
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int top(pStack p, void *top){
    if (p == NULL || p->data == NULL || top == NULL || p->size == 0) {
        return FAIL;
    }
    pDDLL lista = (pDDLL)(p->data);
    return sBegin(lista, top); // Busca o primeiro elemento da DDLL, equivalente ao topo da pilha
}
