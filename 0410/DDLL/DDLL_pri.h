#include "DDLL_pub.h"


typedef struct DDLL {
       struct NoDDLL *Begin;           // ponteiro para o primeiro nó da lista
       int sizedata;                            // tamanho da informação contida nos nós
} DDLL;

typedef struct NoDDLL{
         void *dados;                              // ponteiro para os dados do nó
         struct NoDDLL *prox;                // ponteiro para o próximo elemento
         struct NoDDLL *ant;                  // ponteiro para o elemento anterior
} NoDDLL;
