#include "pDDLL_pub.h"
#include "DDLL_pub.h"
#ifndef _PDDLL_priv_H_
#define _PDDLL_priv_H_

typedef struct DDLL {
       struct NoDDLL *Begin;           // ponteiro para o primeiro nó da lista
       struct NoDDLL *End;              // ponteiro para o último nó da lista
       int sizedata;                            // tamanho da informação contida nos nós
} DDLL;

typedef struct NoDDLL{
         void *dados;                              // ponteiro para os dados do nó
         struct NoDDLL *prox;                // ponteiro para o próximo elemento
         struct NoDDLL *ant;                  // ponteiro para o elemento anterior
} NoDDLL;

#endif