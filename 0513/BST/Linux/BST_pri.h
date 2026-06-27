#include "BST_pub.h"
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    void *dados;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// Definição da estrutura da árvore binária de busca (BST)
typedef struct BST {
    struct Node *raiz;
    int sizedata;
} BST;