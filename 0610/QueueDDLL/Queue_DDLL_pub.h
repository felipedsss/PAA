#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

/* TDAPilha_publico.h */

typedef struct Queue *pQueue, **ppQueue;

int queue(ppQueue pp, int sizedata);
int unQueue(ppQueue pp);

int push(pQueue p, void *element);
int pop(pQueue p, void *element);

int cleanqueue(pQueue p);
int top(pQueue p, void *top);