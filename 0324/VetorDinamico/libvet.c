#include "libvet.h"
#include <stdio.h>
#include <stdlib.h>

void initDynamicIntArray(DynamicIntArray *vec, size_t initial_capacity) {
    // alloca memória para o array dinâmico e define o tamanho inicial como zero
    vec->array = (int *)malloc(initial_capacity * sizeof(int));
    vec->size=0;
    vec->capacity=initial_capacity;


    
}

void pushBack(DynamicIntArray *vec, int value) {
    if (vec->size == vec->capacity){
        //quando o tamanho se iguala a capacidade, dobra a capacidade e realoca
        //espaço na memória conforme a nova capacidade
        vec->capacity *= 2;
        vec->array = (int *)realloc(vec->array, vec->capacity * sizeof(int));

    }
    //incrementa o tamanho do vetor e define como último elemento o parâmetro
    //recebido
    vec->array[vec->size++] = value;
    // TODO
}

void freeDynamicIntArray(DynamicIntArray *vec) {
    //libera a memória do vetor dinâmico
    free(vec->array);
    vec->array = NULL;
    // TODO
}