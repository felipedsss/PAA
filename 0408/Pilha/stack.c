#include "stack_pub.h"
#include "stack_pri.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// "Construtor": aloca memória e inicializa as variáveis
int stack(ppStack pp, int size, int sizedata){
    *pp = malloc(sizeof(Stack)); // aloca na memória o espaço correspondente ao tamanho de uma pilha
    if (*pp == NULL) //se a alocação não funcionar, retorne erro
        return FAIL; 
    (*pp)->size = 0; //o tamanho inicial é 0
    (*pp)->sizedata = sizedata; //o tamanho padrão do dado é sizedata
    (*pp)->data = malloc(size * sizedata); //aloca na memória o espaço correspondente ao tamanho do dado vezes o tamanho da pilha
    if ((*pp)->data == NULL) { // se a alocação falhar não der certo:
        free(*pp); //libera a pilha e retorne erro
        return FAIL; 
    }
    return SUCESS; 
}
// "Destrutor": libera memória da estrutura
int unstack(ppStack pp){
    if (*pp != NULL){ // se a pilha não for nula
        
        free((*pp)->data); //libere os dados da pilha na memória
        free(*pp); //libere a pilha a pilha na memória
        return SUCESS; 
    }
    return FAIL;
}
// **** "Operações de manipulação" ****
// Empilha um elemento 
// Empilha um elemento 
int push(pStack p, void *element) {
    if (p != NULL) {  // se a pilha não for nula:
        // Calcula o endereço do novo elemento na pilha
        char *dest = (char *)p->data + (p->size * p->sizedata); //criamos um string fazendo um casting dos dados, usando o deslocamento correspondente ao produto do tamanho da pilha pelo tamanho do dado
        // Copia os bytes do elemento para a pilha
        memcpy(dest, element, p->sizedata); //colocamos o elemento no lugar da string criada
        p->size++; //aumenta o tamanho da pilha
        return SUCESS; 
    }
    return FAIL; 
}
// Desempilha um elemento
int pop(pStack p, void *element) {
    if (p != NULL && p->size > 0) {//se a pilha não for nula nem vazia:
        // Calcula o endereço do elemento no topo da pilha
        char *top_element = (char *)p->data + ((p->size - 1) * p->sizedata); //criamos a string do topo fazendo um casting dos dados da pilha, usando o deslocamento correspondente ao produto tamanho da pilha antes do último elemento pelo tamanho do dado
        // Copia os bytes do topo da pilha para o elemento de destino
        memcpy(element, top_element, p->sizedata); //colocamos a string criada no elemento passado por referência
        // Reduz o tamanho da pilha
        p->size--;
        // Se a pilha estiver vazia, libere a memória alocada
        if (p->size == 0) { //se foi retirado o último elemento da pilha
            free(p->data); //limpa os dados do elemento
            p->data = NULL; // Define o ponteiro de dados como NULL para indicar que não há mais dados
        }
        return SUCESS; 
    }
    return FAIL; 
}

// Remove todos os dados da pilha mantendo o descritor alocado.
int cleanStack(pStack p){
    if (p != NULL){ //se a pilha não for nula
        p->size = 0; //o tamanho da pilha se torna zero
        return SUCESS; 
    }
}

// **** "Operações de acesso" ****
// Retorna uma cópia do dado do topo
int top(pStack p, void *top){
    if (p != NULL && p->size > 0) {
        // Calcula o endereço do elemento no topo da pilha
        char *top_element = (char *)p->data + ((p->size - 1) * p->sizedata); //da mesma forma que a função pop, criamos a string do topo fazendo um casting dos dados da pilha, usando o deslocamento correspondente ao produto tamanho da pilha antes do último elemento pelo tamanho do dado
        // Copia os bytes do topo da pilha para o elemento de destino
        memcpy(top, top_element, p->sizedata); //copia o elemento criado para a variável top que foi passada por referência
        return SUCESS; 
    }
    return FAIL; 
}

