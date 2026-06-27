#ifndef _QDBST_PRIVADO_H_
#define _QDBST_PRIVADO_H_

/*
Observe o arquivo QDB_priv.h que 
já inclui as interfaces da funções 
das bibliotecas DDLL e BST além 
dos ponteiros para os descritos 
das referidas bibliotecas.
*/

#include "BST_pub.h"
#include "DDLL_pub.h"
#include "QDBST_pub.h"
#include <string.h>
#include <stdio.h>


/*
Os dados recebidos do usuário serão 
encapsulados em um pacote que inclui 
a chave (índice) e os dados propriamente 
ditos. Esses pacotes serão armazenados 
na BST.Além disso, o índice também será 
armazenado na QD, seguindo as regras de 
uma fila clássica, nas quais a inserção 
ocorre no final e a remoção ou busca no início.
*/
typedef struct pacote {
    int index; //chave (índice)
    void *data; //dados propriamente ditos
} pacote;

/*
A QDB é uma estrutura descritora que 
encapsula uma Queue Dynamic (QD), 
baseada na Dynamic Doubly Linked List 
(DDLL), e uma Binary Search Tree (BST). 
*/
typedef struct QDBST {
/*
Queue Dynamic (QD): A QD é uma estrutura 
de fila dinâmica que armazena índices gerados 
aleatoriamente. Esta estrutura é implementada 
usando a Dynamic Doubly Linked List (DDLL) 
para permitir inserção e remoção eficientes 
tanto no início quanto no final da fila.
*/
    pDDLL qd;
/*
Binary Search Tree (BST): A BST é utilizada 
para armazenar os índices como chaves de 
busca associadas aos dados fornecidos pelo usuário. 
Isso permite uma busca eficiente dos dados associados 
aos índices, garantindo um desempenho rápido e eficiente.
*/
    pBST bst;
    int sizedata;
} QDBST;



 


/*
Ponteiro para a função de print do usuário.
Considere declarar um ponteiro para a função 
recebida do usuário no QDB_priv. Isso permitirá 
que a biblioteca QDB desempacote o dado recebido 
da BST, removendo a chave e, posteriormente, 
chame a função de impressão do próprio usuário 
com o dado original.
*/
void (*printusuario)(void *p);
#endif
//test area
