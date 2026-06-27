#include "queue_pub.h"
#include "queue_pri.h"
#include <stdlib.h>

// "Construtor": aloca memória e inicializa as variáveis
int cQueue(ppQueue pf, int size, int sizedata){
    *pf = (pQueue)malloc(sizeof(Queue)); // Alocando memória para a estrutura da fila
    if (*pf == NULL) // verificar se o ponteiro da fila é nulo
        return FAIL; 

    (*pf)->size = size; //tamanho da fila
    (*pf)->sizedata = sizedata; //tamanho do elemento da fila
    (*pf)->data = malloc(size * sizedata); //aloca o na memória o espaço equivalente ao produto do elemento pelo tamanho da fila
    if ((*pf)->data == NULL) { // se a alocação falhar
        free(*pf);  //libera a fila da memória
        return FAIL; 
    }
    (*pf)->inicio = 0; //a posição do início da fila é 0
    (*pf)->fim = 0; //a posição do  fim da fila é 0
    (*pf)->enqueued = 0; // o número de elementos enfileirados é 0
    return SUCESS; 
}

// "Destrutor": libera memória da estrutura
int dQueue(ppQueue pf){
    if (*pf != NULL){ // se a fila não for nula
    free((*pf)->data); //libera os dados da fila
    free(*pf);  //libera a fila
    return SUCESS; }
    return FAIL;
}

// **** "Operações de manipulação" ****
// Enfileira um elemento 
int queue(pQueue f, void *element){
    if (element != NULL && f != NULL){ //se o elemento não for nulo e se a fila não for nula
    if (f->enqueued == f->size){ //se todos os espaços foram enfileirados
        return FAIL; //falha, pois não é possível envileirar mais
    }

    
    for (int i = 0; i < f->sizedata; i++) { //contador varre o equivalente a um elemento
        *((char *)(f->data) + (f->fim * f->sizedata) + i) = *((char *)element + i); //copia a string contida em element para f->data char a char
    }

    f->fim = (f->fim + 1) % f->size; //incrementa o fim da fila
    f->enqueued++;  //adiciona um ao número de enfileirados
    return SUCESS; }
    return FAIL;
}

// Desenfileira um elemento
int unqueue(pQueue f, void *element){ 
    if (f != NULL){ //se a fila não for nul
    if (f->enqueued == 0){ //se não houver enfileirados
        return FAIL;  
    }

    
    for (int i = 0; i < f->sizedata; i++) { //contador varre o equivalente a um elemento
        *((char *)element + i) = *((char *)(f->data) + (f->inicio * f->sizedata) + i); //copia a string contida em element para f->data char a char
    }

    f->inicio = (f->inicio + 1) % f->size; //incrementa o início da fila
    f->enqueued--; //diminui um do número de enfileirados
    return SUCESS; 
    }
    return FAIL;
}

// Remove todos os dados da fila mantendo o descritor alocado.
int cleanQueue(pQueue f){
    f->inicio = 0; //início da fila é igual a zero
    f->fim = 0;  //fim da fila é igual a zero
    f->enqueued = 0; //número de enfileirados é igual a zero
    return SUCESS; 
}

// **** "Operações de acesso" ****
// Retorna o máximo da fila
int sizeQueue(pQueue f){
    return f->size; 
}

// Verifica se a fila está cheia
int fullQueue(pQueue f){
    return f->enqueued == f->size; //a fila está cheia se o número de enfileirados equivale ao tamanho máximo da fila
}