#include "mylib_pri.h"


int criarTDA(ppTDA pp, int tamanho_info){
    if(!(*pp = (TDA*) malloc(sizeof(TDA)))) return FRACASSO; //
    
    (*pp)->tamanho_info = tamanho_info;
    return SUCESSO;
}
int retornarTDA_info1(pTDA p, int *TDA_info1){
    *TDA_info1 = p->TDA_info1;
    return SUCESSO;
}
int alterarTDA(pTDA p, int TDA_info){
    p->TDA_info1 = TDA_info;
    return SUCESSO;
}
int destroirTDA(ppTDA pp){
    
    free(*pp);
    *pp = NULL;
    return SUCESSO;
}
