/* Arquivo EXEMPLO DE Aplicacao */
// MODIFIQUEM-o, CORRIJAM-o!
//#include "BST_pub.h" //Este include foi necessário pois o main.h se encontra somente para leitura
#include "main.h"
/*
Função compara dados recebe dois inteiros como argumento e retorna a diferença entre os dois
*/
int comparaDados(void *a, void *b) {
    if (a == NULL || b == NULL) {
        printf("Erro: Ponteiros nulos recebidos\n");
        return 0; // ou outro valor que faça sentido para sua lógica
    }

    // Convertendo os ponteiros para inteiros e comparando os valores
    int valor_a = *(int *)a;
    int valor_b = *(int *)b;

    printf("Comparando %d com %d\n", valor_a, valor_b);

    if (valor_a < valor_b) {
        return -1;
    } else if (valor_a > valor_b) {
        return 1;
    } else {
        return 0;
    }
}

void process(void *p) {
    // Supondo que os dados na árvore sejam inteiros
    printf("%d ", *(int *)p);
}
int main(int argc, char *argv[]) {
    
    /* TODO */
    printf("TESTING\n");
    pBST BSTTeste = NULL;
    cBST(&BSTTeste, sizeof(int));

    int novo;
    int endFlag = 0;
    while (endFlag < 6) {
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
    //TESTE DE sBST
    printf("Testando Busca\n");
    void *numSearch = (void *)11;
    
    if ((sBST(BSTTeste, &numSearch, comparaDados))==SUCESS) {
        printf("ENCONTRADO\n");
    } else {
        printf("NÃO ENCONTRADO\n");
    }
    
	//TESTE DE emptyBST
    if((emptyBST(BSTTeste)) == SUCESS){
        printf("BST EMPTY\n");
    } else {
        printf("BST NOT EMPTY\n");
    }
    
    //TESTE PERCURSOS
    //PRE ORDEM

    // Chamar a função de percurso em ordem
    printf("Percurso em Ordem:\n");
    orderPath(BSTTeste, process);

    // Chamar a função de percurso em pré-ordem
    printf("Percurso em Pré-ordem:\n");
    preorderPath(BSTTeste, process);

    // Chamar a função de percurso em pós-ordem
    printf("Percurso em Pós-ordem:\n");
    postorderPath(BSTTeste, process);

	/* TODO */
	if((dBST(&BSTTeste)) == SUCESS){
        printf("BST DELETED\n");
    }
    return 0;
}
