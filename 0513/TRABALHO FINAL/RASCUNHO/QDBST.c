#include <stdlib.h>
#include <string.h>
#include "QDBST_pri.h"


// Comparação de nós da QDB
int compareQDBNode(void *p1, void *p2) {
    pacote *a = (pacote *)p1;
    pacote *b = (pacote *)p2;
    if (a->index < b->index) return -1;
    if (a->index > b->index) return 1;
    return 0;
}

// Criação da QDB
int cQDB(ppQDB pp, int sizedata) {
    (*pp) = (pQDB)malloc(sizeof(QDBST));
    if (*pp == NULL)
        return FAIL;
    
    (*pp)->sizedata = sizedata;

    if (cDDLL(&(*pp)->qd, sizeof(int)) != SUCCESS) {
        free(*pp);
        return FAIL;
    }
    (*pp)->bst = NULL;
    if (cBST(&(*pp)->bst, sizeof(pacote)) != SUCCESS) {
        dDDLL(&(*pp)->qd);
        free(*pp);
        return FAIL;
    }

    return SUCCESS;
}

// Destruição da QDB
int dQDB(ppQDB pp) {
    if (pp == NULL || *pp == NULL)
        return FAIL;

    //limpar todos os dados alocados no pacote na função iBST
    int intret;
    while (rQDB((*pp), &intret) == SUCCESS) {
        continue;
    }
    //remover a árvore e a fila DDLL em seguida
    dBST(&(*pp)->bst);
    dDDLL(&(*pp)->qd);
    free(*pp);
    *pp = NULL;
    return SUCCESS;
}

// Inserção na QDB
int iQDB(pQDB p, void *new) {
    if (p == NULL || new == NULL)
        return FAIL;
    int index = rand();
    if (iEnd(p->qd, &index) != SUCCESS) {
        return FAIL;
    }
    //Criar pacote com memória alocada para receber os dados
    pacote newPacote;
    newPacote.index = index;
    newPacote.data = (void *)malloc(p->sizedata);
    memcpy(newPacote.data, new, p->sizedata);
       

    if (iBST(p->bst, &newPacote, compareQDBNode) != SUCCESS) {
        free(newPacote.data);
        rEnd(p->qd, NULL);  // Removing the index from the queue
        return FAIL;
    }

    return SUCCESS;
}

// Busca na QDB
int sQDB(pQDB p, void *new) {
    if (p == NULL || new == NULL) {
        fprintf(stderr, "sQDB: Invalid input pointers.\n");
        return FAIL;
    }
    
    //Encontrar o índice no elemento inicial da fila
    int index;

    if (sBegin(p->qd, &index) != SUCCESS) {
        return FAIL;
    }
    //Criar um pacote com o índice encontrado, ele receberá os dados do respectivo nó na BST
    pacote buscaPacote;
    buscaPacote.index = index;

    //Encontrar o pacote no BST que possui o índice encontrado
    if (sBST(p->bst, &buscaPacote, compareQDBNode) != SUCCESS) {
        return FAIL;
    }
    
    memcpy(new, buscaPacote.data, p->sizedata);
    return SUCCESS;
}

// Remoção da QDB
int rQDB(pQDB p, void *new) {
    if (p == NULL || new == NULL) {
        fprintf(stderr, "rQDB: p or new is NULL.\n");
        return FAIL;
    }

    int index;
    if (rBegin(p->qd, &index) != SUCCESS) {
        return FAIL;
    }
    
    pacote buscaPacote;
    buscaPacote.index = index;

    if (rBST(p->bst, &buscaPacote, compareQDBNode) != SUCCESS) {
        fprintf(stderr, "rQDB: rBST failed.\n");
        return FAIL;
    }
    
    memcpy(new, buscaPacote.data, p->sizedata);
    free(buscaPacote.data);
    return SUCCESS;
}

// Impressão da QDB
int prQDB(pQDB p, void (*printall)(void *p)) {
    printf("[Index]\t(User data)\n");

    if (p == NULL || printall == NULL)
        return FAIL;

    return orderPath(p->bst, printall);
}