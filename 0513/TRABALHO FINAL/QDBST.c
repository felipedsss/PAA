#include <stdlib.h>
#include <string.h>
#include "QDBST_pri.h"

// Comparação de nós da QDB
int compareQDBNode(void *p1, void *p2) {
    if (p1 == NULL || p2 == NULL)
        return 0;
    pacote *a = (pacote *)p1;
    pacote *b = (pacote *)p2;
    if (a->index == NULL || b->index == NULL)
        return 0;
    return a->index - b->index;
}

// Criação da QDB
/*
Esta função é responsável por criar a QDB, 
alocando memória e inicializando todas as estruturas 
necessárias. O parâmetro pp é um ponteiro para um 
ponteiro para a QDB, que será inicializado por esta função.
sizedata especifica o tamanho dos dados que serão 
armazenados na QDB.*/
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
/*
Esta função destroi a QDB, liberando toda a memória 
alocada para suas estruturas internas. 
O parâmetro pp é um ponteiro para um ponteiro para a 
QDB que será destruída.
*/
int dQDB(ppQDB pp) {
    if (pp == NULL || *pp == NULL)
        return FAIL;
    //limpar todos os dados alocados no pacote na função iBST
    

    int index;
    while (rBegin((*pp)->qd, &index) == SUCCESS){
        pacote buscaPacote;
        buscaPacote.index = index;
        sBST((*pp)->bst, &buscaPacote, compareQDBNode);
        free(buscaPacote.data);
    }
    /*
    while (rQDB((*pp), elementoRemovido) == SUCCESS) {
        continue;
    }
    */

    //remover a árvore e a fila DDLL em seguida
    dBST(&(*pp)->bst);
    dDDLL(&(*pp)->qd);
    free(*pp);
    *pp = NULL;
    return SUCCESS;
}

// Inserção na QDB
/*
 Esta função insere um novo elemento na QDB. 
 O parâmetro p é um ponteiro para a QDB, 
 e new é um ponteiro para os dados que serão inseridos 
 na QDB.
*/
int iQDB(pQDB p, void *new) {
    if (p == NULL)
        return FAIL;
    int index = rand();
    if (iEnd(p->qd, &index) != SUCCESS) {
        return FAIL;
    }
    //Criar pacote com memória alocada para receber os dados
    pacote newPacote;
    newPacote.index = index;
    newPacote.data = (void *)malloc(p->sizedata);
    if (newPacote.data == NULL){
        rEnd(p->qd, NULL);  
        return FAIL;
    }
    memcpy(newPacote.data, new, p->sizedata);
    if (iBST(p->bst, &newPacote, compareQDBNode) != SUCCESS) {
        free(newPacote.data);
        rEnd(p->qd, NULL);  // Removing the index from the queue
        return FAIL;
    }
    return SUCCESS;
}

/*
Para acessar os dados armazenados na BST, siga as regras da QD. 
Isso significa que as funções sQDB e rQDB devem remover ou buscar 
o dado no início da QD para, em seguida, encontrar a chave 
correspondente na BST e, por fim, retornar o dado original do usuário.
*/

// Busca na QDB
/*
Esta função busca um elemento na QDB com base 
no índice fornecido. O parâmetro p é um ponteiro 
para a QDB, e new é um ponteiro para os dados associados 
ao índice a ser buscado.
*/
int sQDB(pQDB p, void *new) {
    if (p == NULL) {
        printf("sQDB: Invalid input pointers.\n");
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
/*
Esta função remove um elemento da QDB com base 
no índice fornecido. O parâmetro p é um ponteiro 
para a QDB, e new é um ponteiro para os dados 
associados ao índice a ser removido.
*/
int rQDB(pQDB p, void *new) {
    if (p == NULL) {
        printf("rQDB: p or new is NULL.\n");
        return FAIL;
    }
    int index;
    if (rBegin(p->qd, &index) != SUCCESS) {
        return FAIL;
    }
    pacote buscaPacote;
    buscaPacote.index = index;
    if (sBST(p->bst, &buscaPacote, compareQDBNode) != SUCCESS) {
        return FAIL;
    }
    if (emptyBST(p->bst) == SUCCESS)
        return FAIL;
    if (rBST(p->bst, &buscaPacote, compareQDBNode) != SUCCESS) {
        printf("rQDB: rBST failed.\n");
        free(buscaPacote.data);
        return FAIL;
    }
    memcpy(new, buscaPacote.data, p->sizedata);
    free(buscaPacote.data);
    buscaPacote.data = NULL;
    return SUCCESS;
}

/*
A função de impressão deve ser definida na aplicação, 
pois somente ela conhece o formato dos dados. No entanto, 
lembre-se de que os dados armazenados na BST não consistem 
puramente nos dados recebidos pelo usuário, pois a QDB a
crescenta o índice (chave) ao pacote armazenado.
*/
void printaLinha(void *p){
    if (p != NULL)
    {
        pacote *printPacote = ( pacote *)(p);
        printf("[%i]", printPacote->index);
        printusuario(printPacote->data);
        printf("\n");
    }
}

/*
Esta função imprime todos os elementos armazenados na QDB. 
O parâmetro p é um ponteiro para a QDB, e printall é um 
ponteiro para uma função de impressão que será aplicada a 
cada elemento da QDB para imprimir seus dados.
Utilize a função orderPath da BST para imprimir os 
dados em ordem de chave. Essa função requer uma função de 
impressão como parâmetro, já que a estrutura BST 
desconhece o formato dos dados armazenados.
*/
// Impressão da QDB
int prQDB(pQDB p, void (*printall)(void *p)) {
    printf("[Index]\t(User data)\n");
    if (p == NULL || printall == NULL)
        return FAIL;
    printusuario = printall;
    return orderPath(p->bst, printaLinha);
}
