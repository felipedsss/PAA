#include "Queue_DDLL_pri.h"
#include "Queue_DDLL_pub.h"
#include "DDLL_pub.h"

int cQueue(ppQueue pp, int sizedata){
    pDDLL fila = NULL;
    if(cDDLL(&fila, sizedata)){
        return FAIL;
    } else {
        Queue *p = (Queue*)malloc(sizeof(Queue));
        if (p == NULL) {
            dDDLL(&fila); // Limpa a DDLL em caso de falha na alocação da fila
            return FAIL;
        }
        p->fila = fila;
        //p->data = lista;
        
        *pp = p;
        return SUCCESS;
    }
}

int dQueue(ppQueue pp){
    Queue *p = *pp;
    if (p == NULL) return FAIL;
    dDDLL(&p->fila); // Destrói a DDLL associada à fila
    free(p); // Libera a memória alocada para a estrutura Queue
    *pp = NULL;
    return SUCCESS;
}

int queue(pQueue p, void *element){
    if (p == NULL || p->fila == NULL || element == NULL) {
        return FAIL;
    }
    pDDLL lista = p->fila;
    if (iEnd(lista, element) == SUCCESS) {
        //p->size++; // Incrementa o tamanho da fila após a inserção
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int unqueue(pQueue p, void *element){
    if (p == NULL || p->fila == NULL || element == NULL) {
        return FAIL;
    }
    pDDLL lista = (pDDLL)(p->fila);
    if (rBegin(lista, element) == SUCCESS) {
        //p->size--; // Decrementa o tamanho da fila após a remoção
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int cleanQueue(pQueue p){
    if (p == NULL || p->fila == NULL) {
        return FAIL;
    }
    pDDLL lista = p->fila;
    if (cleanDDLL(lista) == SUCCESS) {
        //p->size = 0; // Redefine o tamanho da fila como 0 após a limpeza
        return SUCCESS;
    } else {
        return FAIL;
    }
}

int top(pQueue p, void *top){
    if (p == NULL || p->fila == NULL || top == NULL) {
        return FAIL;
    }
    pDDLL lista = p->fila;
    return sBegin(lista, top); // Busca o primeiro elemento da DDLL, equivalente ao topo da fila
}
// **** "Operações de acesso" ****
// Retorna o máximo da fila
int sizeQueue(pQueue p){
    if (p == NULL || p->fila == NULL || top == NULL) {
        return FAIL;
    }    
    pDDLL lista = p->fila;
    return countElements(lista);
}

// Verifica se a fila está cheia
int fullQueue(pQueue p){
    //return f->enqueued == f->size; //a fila está cheia se o número de enfileirados equivale ao tamanho máximo da fila
}