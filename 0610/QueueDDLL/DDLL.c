#include "DDLL_pri.h"
#include <stdlib.h>
// Funções básicas de uma DDLL
/*
Funções de Criação e Destruição
*/

/*
1. int cDDLL(ppDDLL pp, int sizedata)
  - Descrição: Cria uma nova lista duplamente encadeada.
   - Parâmetros:
     - `pp`: Ponteiro para o ponteiro que aponta para a lista (referência à lista).
     - `sizedata`: Tamanho dos dados que serão armazenados em cada elemento da lista.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha na alocação de memória.
*/

int cDDLL(ppDDLL pp, int sizedata) {
    (*pp) = (pDDLL)malloc(sizeof(DDLL));
    if (*pp == NULL)
        return FAIL;
    (*pp)->sizedata = sizedata;
    (*pp)->Begin = NULL;

    return SUCCESS;
}

/*
2. int dDDLL(ppDDLL pp)
   - Descrição: Destroi a lista duplamente encadeada e libera toda a memória alocada.
   - Parâmetros:
     - `pp`: Ponteiro para o ponteiro que aponta para a lista (referência à lista).
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/

int dDDLL(ppDDLL pp) {
    if (pp == NULL || *pp == NULL)
        return FAIL;
    
    cleanDDLL(*pp); // Limpa a lista antes de destruí-la

    free(*pp); // Libera a memória alocada para a lista
    *pp = NULL; // Define o ponteiro para a lista como NULL

    return SUCCESS;
}
/*
3. int cleanDDLL(pDDLL p)
   - Descrição: Remove todos os elementos da lista, mantendo-a vazia.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/

int cleanDDLL(pDDLL p) {
    if (p == NULL) {
        return FAIL;
    }

    NoDDLL *current = p->Begin;
    NoDDLL *temp;

    // Percorre a lista e libera a memória alocada para cada nó
    while (current != NULL) {
        temp = current; // Salva o nó atual temporariamente
        current = current->prox; // Avança para o próximo nó

        free(temp->dados); // Libera a memória alocada para os dados do nó
        free(temp); // Libera a memória alocada para o próprio nó
    }

    p->Begin = NULL; // Define o ponteiro de início da lista como NULL, indicando que a lista está vazia

    return SUCCESS;
}

/*
Funções de Inserção

4. int iBegin(pDDLL p, void *element)
   - Descrição: Insere um elemento no início da lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `element`: Ponteiro para os dados do elemento a ser inserido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/

int iBegin(pDDLL p, void *element) {
    if (p == NULL || element == NULL)
        return FAIL;

    NoDDLL *newNode = (NoDDLL*)malloc(sizeof(NoDDLL));
    if (newNode == NULL)
        return FAIL;

    newNode->dados = malloc(p->sizedata);
    if (newNode->dados == NULL) {
        free(newNode);
        return FAIL;
    }

    memcpy(newNode->dados, element, p->sizedata);

    newNode->prox = p->Begin;
    newNode->ant = NULL;

    if (p->Begin != NULL) {
        p->Begin->ant = newNode;
    }

    p->Begin = newNode;

    return SUCCESS;
}

/*
5. int iEnd(pDDLL p, void *element)
   - Descrição: Insere um elemento no final da lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `element`: Ponteiro para os dados do elemento a ser inserido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/

int iEnd(pDDLL p, void *element) {
    if (p == NULL || element == NULL)
        return FAIL;

    NoDDLL *current = p->Begin;

    if (current == NULL) {
        return iBegin(p, element); // Se a lista estiver vazia, insere no início
    }

    while (current->prox != NULL) {
        current = current->prox;
    }

    current->prox = (NoDDLL*)malloc(sizeof(NoDDLL));
    if (current->prox == NULL)
        return FAIL;

    current->prox->dados = malloc(p->sizedata);
    if (current->prox->dados == NULL) {
        free(current->prox);
        return FAIL;
    }

    memcpy(current->prox->dados, element, p->sizedata);
    current->prox->ant = current;
    current->prox->prox = NULL;

    return SUCCESS;
}


/*
6. int iPosition(pDDLL p, int N, void *element)
   - Descrição: Insere um elemento em uma posição específica na lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `N`: Posição na lista onde o elemento será inserido.
     - `element`: Ponteiro para os dados do elemento a ser inserido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` se a posição for inválida.

Funções de Remoção
*/

int iPosition(pDDLL p, int N, void *element) {
    if (p == NULL || N < 0 || element == NULL)
        return FAIL;

    NoDDLL *current = p->Begin;
    for (int i = 0; i < N && current != NULL; i++) {
        current = current->prox;
    }

    if (current == NULL)
        return FAIL;

    NoDDLL *newNode = (NoDDLL*)malloc(sizeof(NoDDLL));
    if (newNode == NULL)
        return FAIL;

    newNode->dados = malloc(p->sizedata);
    if (newNode->dados == NULL) {
        free(newNode);
        return FAIL;
    }
    memcpy(newNode->dados, element, p->sizedata);

    newNode->prox = current->prox;
    newNode->ant = current;
    if (current->prox != NULL) {
        current->prox->ant = newNode;
    }
    current->prox = newNode;

    return SUCCESS;
}
/*
7. int rBegin(pDDLL p, void *element)
   - Descrição: Remove o primeiro elemento da lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `element`: Ponteiro para armazenar os dados do elemento removido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/
int rBegin(pDDLL p, void *element) {
    if (p == NULL || p->Begin == NULL)
        return FAIL;

    NoDDLL *temp = p->Begin;

    memcpy(element, temp->dados, p->sizedata);
    
    p->Begin = temp->prox;
    if (temp->prox != NULL) {
        temp->prox->ant = NULL;
    }

    free(temp->dados);
    free(temp);

    return SUCCESS;
}

/*
8. int rEnd(pDDLL p, void *element)
   - Descrição: Remove o último elemento da lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `element`: Ponteiro para armazenar os dados do elemento removido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` em caso de falha.
*/

int rEnd(pDDLL p, void *element) {
    if (p == NULL || p->Begin == NULL)
        return FAIL;

    NoDDLL *current = p->Begin;
    NoDDLL *prev = NULL;

    while (current->prox != NULL) {
        prev = current;
        current = current->prox;
    }

    memcpy(element, current->dados, p->sizedata);

    if (prev != NULL) {
        prev->prox = NULL;
    } else {
        p->Begin = NULL;
    }

    free(current->dados);
    free(current);

    return SUCCESS;
}
/*
9. int rPosition(pDDLL p, int N, void *element)
   - Descrição: Remove o elemento de uma posição específica na lista.
   - Parâmetros:
     - `p`: Ponteiro para a lista duplamente encadeada.
     - `N`: Posição do elemento a ser removido.
     - `element`: Ponteiro para armazenar os dados do elemento removido.
   - Retorno:
     - `0` em caso de sucesso.
     - `1` se a posição for inválida.

Funções de Busca
*/

int rPosition(pDDLL p, int N, void *element) {
    if (p == NULL || N < 0)
        return FAIL;

    NoDDLL *current = p->Begin;
    for (int i = 0; i < N && current != NULL; i++) {
        current = current->prox;
    }

    if (current == NULL)
        return FAIL;

    memcpy(element, current->dados, p->sizedata);

    if (current->ant != NULL) {
        current->ant->prox = current->prox;
    } else {
        p->Begin = current->prox;
    }

    if (current->prox != NULL) {
        current->prox->ant = current->ant;
    }

    free(current->dados);
    free(current);

    return SUCCESS;
}

/*
10. int sBegin(pDDLL p, void *element)
    - Descrição: Retorna o primeiro elemento da lista.
    - Parâmetros:
      - `p`: Ponteiro para a lista duplamente encadeada.
      - `element`: Ponteiro para armazenar os dados do elemento encontrado.
    - Retorno:
      - `0` em caso de sucesso.
      - `1` se a lista estiver vazia.

*/

int sBegin(pDDLL p, void *element) {
    if (p == NULL || p->Begin == NULL)
        return FAIL;

    memcpy(element, p->Begin->dados, p->sizedata);

    return SUCCESS;
}
/*
11. int sEnd(pDDLL p, void *element)
    - Descrição: Retorna o último elemento da lista.
    - Parâmetros:
      - `p`: Ponteiro para a lista duplamente encadeada.
      - `element`: Ponteiro para armazenar os dados do elemento encontrado.
    - Retorno:
      - `0` em caso de sucesso.
      - `1` se a lista estiver vazia.
*/


int sEnd(pDDLL p, void *element) {
    if (p == NULL || p->Begin == NULL)
        return FAIL;

    NoDDLL *current = p->Begin;
    while (current->prox != NULL) {
        current = current->prox;
    }

    memcpy(element, current->dados, p->sizedata);

    return SUCCESS;
}

/*
12. int sPosition(pDDLL p, int N, void *element)
    - Descrição: Retorna o elemento de uma posição específica na lista.
    - Parâmetros:
      - `p`: Ponteiro para a lista duplamente encadeada.
      - `N`: Posição do elemento a ser encontrado.
      - `element`: Ponteiro para armazenar os dados do elemento encontrado.
    - Retorno:
      - `0` em caso de sucesso.
      - `1` se a posição for inválida.

*/

int sPosition(pDDLL p, int N, void *element) {
    if (p == NULL || N < 0)
        return FAIL;

    NoDDLL *current = p->Begin;
    for (int i = 0; i < N && current != NULL; i++) {
        current = current->prox;
    }

    if (current == NULL)
        return FAIL;

    memcpy(element, current->dados, p->sizedata);

    return SUCCESS;
}

// Funções adicionais

/*
Funções de Utilidade

13. int empty(pDDLL p)
    - Descrição: Verifica se a lista está vazia.
    - Parâmetros:
      - `p`: Ponteiro para a lista duplamente encadeada.
    - Retorno:
      - `0` se a lista estiver vazia.
      - `1` se a lista não estiver vazia.

*/


int empty(pDDLL p) {
    if (p == NULL)
        return SUCCESS;

    return p->Begin == NULL ? SUCCESS : FAIL;
}
/*
14. int countElements(pDDLL p)
    - Descrição: Retorna o número de elementos presentes na lista.
    - Parâmetros:
      - `p`: Ponteiro para a lista duplamente encadeada.
    - Retorno:


*/

int countElements(pDDLL p) {
    if (p == NULL || p->Begin == NULL)
        return 0;

    int count = 0;
    NoDDLL *current = p->Begin;
    while (current != NULL) {
        count++;
        current = current->prox;
    }
    return count;
}