#include "BST_pub.h"
#include "BST_pri.h"
#include <stdlib.h>
#include <string.h>

/*
    Criação de uma BST: A função int cBST(ppBST pp, int sizedata) deve criar 
    uma BST vazia e retornar um código de erro indicando o sucesso ou falha da 
    operação. O parâmetro pp é um ponteiro para ponteiro que será usado para 
    referenciar a BST criada. O parâmetro sizedata indica o tamanho dos dados 
    que serão armazenados em cada nó da BST.
*/
int cBST(ppBST pp, int sizedata){
    *pp = NULL;
    (*pp) = (pBST)malloc(sizeof(BST));
    if (*pp == NULL)
    {
        free(*pp);
        pp = NULL;
        return FAIL;
    }
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
    pp = NULL; // Define o ponteiro para a lista como NULL

    return SUCESS;
}
/*Função auxiliar recursiva para limpeza dos nós da árvore
*/
int cleanNode(Node* node) {
    if (node != NULL) {
        // Limpar recursivamente os nós filhos
        cleanNode(node->esquerda);
        cleanNode(node->direita);
        
        // Liberar a memória associada aos dados e ao nó
        if (node->dados != NULL) {
            free(node->dados);
            node->dados = NULL;
        }
        free(node);
        node = NULL;
    }
    return SUCESS;
}
int comparaNos(void *a, void *b) {
    if (a == NULL || b == NULL) {
        //printf("Erro: Ponteiros nulos recebidos\n");
        return 0; // ou outro valor que faça sentido para sua lógica
    }

    // Convertendo os ponteiros para inteiros e comparando os valores
    int valor_a = *(int *)a;
    int valor_b = *(int *)b;

    //printf("Comparando %d com %d\n", valor_a, valor_b);

    if (valor_a < valor_b) {
        return -1;
    } else if (valor_a > valor_b) {
        return 1;
    } else {
        return 0;
    }
}

/*
    Limpeza de uma BST: A função int cleanBST(pBST p) deve remover todos os 
    elementos de uma BST existente, deixando-a vazia. Ela retorna um código de 
    erro indicando o sucesso ou falha da operação.
*/
int cleanBST(pBST p){
    if (p == NULL)
        return FAIL;

    // Percorre a árvore e remove cada nó usando rBST
    while (p->raiz != NULL) {
        // Remove a raiz atual
        if (rBST(p, p->raiz->dados, comparaNos) == FAIL) {
            // Se a remoção falhar, retorna um código de erro
            return FAIL;
        }
    }

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
        //printf("Inserindo %p\n", (void *)new);

    if (p == NULL || new == NULL || cmp == NULL)
        return FAIL;

    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL)
        return FAIL;

    novoNode->dados = malloc(p->sizedata);
    if (novoNode->dados == NULL) {
        free(novoNode);
        novoNode = NULL;
        return FAIL;
    }
    // Copiar os dados para o novo nó
    memcpy(novoNode->dados, new, p->sizedata);
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;

    if (p->raiz == NULL) {
        // Se a árvore estiver vazia, o novo nó será a raiz
        p->raiz = novoNode;
        return SUCESS;
    }

    // Encontrar o lugar correto para inserir o novo nó
    Node *atual = p->raiz;
    Node *anterior = NULL;

    while (atual != NULL) {
        anterior = atual;
        if (cmp(new, atual->dados) < 0) {
            
            // Vamos para a subárvore esquerda
            atual = atual->esquerda;
        } else if (cmp(new, atual->dados) > 0) {
            // Vamos para a subárvore direita
            atual = atual->direita;
        } else {
            // Se os dados são iguais, não permitimos elementos duplicados
            free(novoNode->dados);
            novoNode->dados = NULL;
            free(novoNode);
            novoNode = NULL;
            return FAIL;
        }
    }

    // Inserir o novo nó
    if (cmp(new, anterior->dados) < 0) {
        anterior->esquerda = novoNode;
    } else {
        anterior->direita = novoNode;
    }
    //printf("Inserido");
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
    if (p == NULL || p == NULL || item == NULL || cmp == NULL)
        return FAIL;

    Node *atual = p->raiz;
    Node *anterior = NULL;

    // Procurando o nó a ser removido
    while (atual != NULL) {
        int cmpResult = cmp(item, atual->dados);
        if (cmpResult == 0) {
            // Encontramos o nó a ser removido
            memcpy(item, atual->dados, p->sizedata);
            if (anterior == NULL) {
                // Se o nó a ser removido é a raiz
                if (atual->esquerda == NULL && atual->direita == NULL) {
                    // Se a raiz não tem filhos
                    free(atual->dados);
                    atual->dados = NULL;
                    free(atual);
                    atual = NULL;
                    p->raiz = NULL;
                } else if (atual->esquerda != NULL && atual->direita != NULL) {
                    // Se a raiz tem dois filhos
                    // Encontrar o nó sucessor na subárvore direita
                    Node *sucessor = atual->direita;
                    Node *sucessorPai = atual;
                    while (sucessor->esquerda != NULL) {
                        sucessorPai = sucessor;
                        sucessor = sucessor->esquerda;
                    }
                    // Substituir os dados do nó a ser removido pelos dados do sucessor
                    free(atual->dados);
                    atual->dados = malloc(p->sizedata);
                    memcpy(atual->dados, sucessor->dados, p->sizedata);
                    // Remover o sucessor
                    if (sucessorPai != atual) {
                        // Se o sucessor não é o filho direito do nó a ser removido
                        sucessorPai->esquerda = sucessor->direita;
                    } else {
                        // Se o sucessor é o filho direito do nó a ser removido
                        atual->direita = sucessor->direita;
                    }
                    free(sucessor->dados);
                    free(sucessor);
                } else {
                    // Se a raiz tem apenas um filho
                    Node *filho = (atual->esquerda != NULL) ? atual->esquerda : atual->direita;
                    free(atual->dados);
                    free(atual);
                    p->raiz = filho;
                }
            } else {
                // Se o nó a ser removido não é a raiz
                if (atual->esquerda == NULL && atual->direita == NULL) {
                    // Se o nó não tem filhos
                    if (anterior->esquerda == atual) {
                        anterior->esquerda = NULL;
                    } else {
                        anterior->direita = NULL;
                    }
                    free(atual->dados);
                    free(atual);
                } else if (atual->esquerda != NULL && atual->direita != NULL) {
                    // Se o nó tem dois filhos
                    // Encontrar o nó sucessor na subárvore direita
                    Node *sucessor = atual->direita;
                    Node *sucessorPai = atual;
                    while (sucessor->esquerda != NULL) {
                        sucessorPai = sucessor;
                        sucessor = sucessor->esquerda;
                    }
                    // Substituir os dados do nó a ser removido pelos dados do sucessor
                    free(atual->dados);
                    atual->dados = malloc(p->sizedata);
                    memcpy(atual->dados, sucessor->dados, p->sizedata);
                    // Remover o sucessor
                    if (sucessorPai != atual) {
                        // Se o sucessor não é o filho direito do nó a ser removido
                        sucessorPai->esquerda = sucessor->direita;
                    } else {
                        // Se o sucessor é o filho direito do nó a ser removido
                        atual->direita = sucessor->direita;
                    }
                    free(sucessor->dados);
                    free(sucessor);
                } else {
                    // Se o nó tem apenas um filho
                    Node *filho = (atual->esquerda != NULL) ? atual->esquerda : atual->direita;
                    if (anterior->esquerda == atual) {
                        anterior->esquerda = filho;
                    } else {
                        anterior->direita = filho;
                    }
                    free(atual->dados);
                    free(atual);
                }
            }
            return SUCESS;
        } else if (cmpResult < 0) {
            // O nó a ser removido está na subárvore esquerda
            anterior = atual;
            atual = atual->esquerda;
        } else {
            // O nó a ser removido está na subárvore direita
            anterior = atual;
            atual = atual->direita;
        }
    }

    // Se chegamos aqui, o nó a ser removido não foi encontrado
    return FAIL;
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
    
    if (p == NULL || p->raiz == NULL) {
        //fprintf(stderr, "Erro: Árvore ou raiz nula.\n");
        return -1;
    }    
    Node *current = p->raiz;
    if (current == NULL) {
        //printf("Erro: a raiz da árvore está vazia.\n");
        return -1;
    }
    
    while (current != NULL) {
        int cmpResult = cmp(item, current->dados);
        
        if (cmpResult == 0) {
            // O elemento foi encontrado
            memcpy(item, current->dados, p->sizedata);
            return SUCESS;
        } else if (cmpResult < 0) {
            // O elemento está na subárvore esquerda
            current = current->esquerda;
        } else {
            // O elemento está na subárvore direita
            current = current->direita;
        }
    }
    // O elemento não foi encontrado na árvore
    return FAIL;
    
}
/*
    Verificação de BST vazia: A função int emptyBST(pBST p) deve verificar se a 
    BST especificada está vazia ou não. Ela retorna um código indicando se a 
    árvore está vazia ou não.
*/
int emptyBST(pBST p){
    if (p == NULL || p->raiz == NULL) {
        // Se o ponteiro para a árvore for nulo ou se a raiz for nula, a árvore está vazia
        return SUCESS;
    } else {
        // Caso contrário, a árvore não está vazia
        return FAIL;
    }
}
/*
    Percursos na BST: As funções orderPath, preorderPath e postorderPath são 
    responsáveis por percorrer a BST em ordem, pré-ordem e pós-ordem, 
    respectivamente. Elas recebem um ponteiro para a raiz da árvore e uma 
    função de callback process que será aplicada a cada nó visitado durante o 
    percurso.
*/


int orderTraversal(Node *node, void (* process)(void *p)) {
    if (node != NULL) {
        orderTraversal(node->esquerda, process); // Visita a subárvore esquerda
        process(node->dados); // Processa o próprio nó
        orderTraversal(node->direita, process); // Visita a subárvore direita
    }
    return SUCESS;
}
int orderPath(pBST pa, void (* process)(void *p)){
    return orderTraversal(pa->raiz, process);
}
int preorderTraversal(Node *node, void (* process)(void *p)) {
    if (node != NULL) {
        process(node->dados); // Processa o próprio nó
        preorderTraversal(node->esquerda, process); // Visita a subárvore esquerda
        preorderTraversal(node->direita, process); // Visita a subárvore direita
    }
    return SUCESS;
}
int preorderPath(pBST pa, void (* process)(void *p)){
    return preorderTraversal(pa->raiz, process);
}


int postorderTraversal(Node *node, void (* process)(void *p)) {
    if (node != NULL) {
        postorderTraversal(node->esquerda, process); // Visita a subárvore esquerda
        postorderTraversal(node->direita, process); // Visita a subárvore direita
        process(node->dados); // Processa o próprio nó
    }
    return SUCESS;
}
int postorderPath(pBST pa, void (* process)(void *p)){
    return postorderTraversal(pa->raiz, process);
}