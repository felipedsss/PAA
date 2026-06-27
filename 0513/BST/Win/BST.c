#include "BST_pub.h"
#include "BST_pri.h"
#include <stdlib.h>


/*
    Criação de uma BST: A função int cBST(ppBST pp, int sizedata) deve criar 
    uma BST vazia e retornar um código de erro indicando o sucesso ou falha da 
    operação. O parâmetro pp é um ponteiro para ponteiro que será usado para 
    referenciar a BST criada. O parâmetro sizedata indica o tamanho dos dados 
    que serão armazenados em cada nó da BST.
*/
int cBST(ppBST pp, int sizedata){
    if (pp != NULL)
       return FAIL;
    (*pp) = (pBST)malloc(sizeof(BST));
    if (*pp == NULL)
        return FAIL;
    
    (*pp)->raiz = NULL;
    (*pp)->sizedata = sizedata;
    return SUCESS;
    

}

/*
    Destruição de uma BST: A função int dBST(ppBST pp) deve destruir uma BST 
    existente, liberando toda a memória alocada para ela. Esta função também 
    deve liberar o ponteiro pp associado à BST, deixando-o nulo. Ela retorna 
    um código de erro indicando o sucesso ou falha da operação.
*/
int dBST(ppBST pp){
    if (pp == NULL || *pp == NULL)
        return FAIL;
    
    cleanBST(*pp); // Limpa a lista antes de destruí-la

    free(*pp); // Libera a memória alocada para a lista
    *pp = NULL; // Define o ponteiro para a lista como NULL

    return SUCESS;
}
/*Função auxiliar recursiva para limpeza dos nós da árvore
*/
int cleanNode(Node* node) {
    if (node != NULL) {
        cleanNode(node->esquerda);
        cleanNode(node->direita);
        free(node->dados);
        free(node);
    }
    return SUCESS;
}

/*
    Limpeza de uma BST: A função int cleanBST(pBST p) deve remover todos os 
    elementos de uma BST existente, deixando-a vazia. Ela retorna um código de 
    erro indicando o sucesso ou falha da operação.
*/
int cleanBST(pBST p){
    if (p == NULL)
        return FAIL;

    // Chama uma função auxiliar recursiva para limpar a árvore
    cleanNode(p->raiz);

    return SUCESS;
}
/*
    Inserção em uma BST: A função 
    int iBST(pBST p, void *new, int (* cmp)(void *p1, void *p2)) deve inserir 
    um novo elemento na BST especificada. O parâmetro new representa o novo 
    elemento a ser inserido, enquanto cmp é um ponteiro para uma função de 
    comparação que determina a ordem dos elementos na árvore. Ela retorna um 
    código de erro indicando o sucesso ou falha da operação.
*/
int iBST(pBST p, void *new, int (* cmp)(void *p1, void *p2)){
    return SUCESS;
}
/*
    Remoção de um elemento em uma BST: A função 
    int rBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)) deve remover 
    o elemento especificado da BST. O parâmetro item representa o elemento a ser 
    removido, enquanto cmp é a função de comparação utilizada para localizar o 
    elemento na árvore. Ela retorna um código de erro indicando o sucesso ou 
    falha da operação.
*/
int rBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)){
    return SUCESS;
}
/*
    Busca em uma BST: A função 
    int sBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)) deve buscar 
    um elemento na BST e retornar um código indicando se o elemento foi 
    encontrado ou não. O parâmetro item representa o elemento a ser buscado, 
    enquanto cmp é a função de comparação utilizada para comparar elementos na 
    árvore.
*/
int sBST(pBST p, void *item, int (* cmp)(void *p1, void *p2)){
    return SUCESS;
}
/*
    Verificação de BST vazia: A função int emptyBST(pBST p) deve verificar se a 
    BST especificada está vazia ou não. Ela retorna um código indicando se a 
    árvore está vazia ou não.
*/
int emptyBST(pBST p){
    return SUCESS;
}

/*
    Percursos na BST: As funções orderPath, preorderPath e postorderPath são 
    responsáveis por percorrer a BST em ordem, pré-ordem e pós-ordem, 
    respectivamente. Elas recebem um ponteiro para a raiz da árvore e uma 
    função de callback process que será aplicada a cada nó visitado durante o 
    percurso.
*/
int orderPath(pBST pa, void (* process)(void *p)){
    return SUCESS;
}
int prerderPath(pBST pa, void (* process)(void *p)){
    return SUCESS;
}
int postorderPath(pBST pa, void (* process)(void *p)){
    return SUCESS;
}