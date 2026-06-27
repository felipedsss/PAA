/* Arquivo EXEMPLO DE Aplicacao */
// MODIFIQUEM-o, CORRIJAM-o!
#include "BST_pub.h" //Este include foi necessário pois o main.h se encontra somente para leitura
#include "main.h"
int comparaDados(int a, int b){
    
    return a-b;
    
}
int main(int argc, char *argv[]) {
    
    /* TODO */
    printf("TESTING");
    pBST BSTTeste = NULL;
    
    cBST(&BSTTeste, 10);
    printf("BST CREATED");
    int novo;
    int endFlag = 0;
    while (endFlag < 5) {
        if (!fscanf(stdin, "%d", &novo)) {
            // printf("FIM de leitura %d\n", novo);
            
            break;
        }
        printf("{%d}", novo);
        
        if((iBST(BSTTeste, &novo, comparaDados)) == SUCESS){
            printf ("(%i)", novo);
        }
        else {
            printf("Erro na insercao\n");
        }
        endFlag++;
    }
	
	/* TODO */
	
    return 0;
}
