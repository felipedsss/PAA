#include "myApp.h"

int minhaFunca (int i) {
    return 1;
}

int main(int argc, char **argv)
{
	pTDA meuTDA;
	int retorno=-9;
	
	if(criarTDA(&meuTDA, sizeof(int))){
		printf("Erro ao criar o TDA.\n");
		exit(1);
	}
	printf("Criacao OK.\n");
	if (alterarTDA(meuTDA, 10)) {
		printf("Erro ao alterar o TDA.\n");
		exit(1);
	}
	printf("Alteracao OK.\n");
	if (retornarTDA_info1(meuTDA, &retorno)) {
		printf("Erro ao alterar o TDA.\n");
		exit(1);
	}
	printf("Retorno OK (valor = %d).\n",retorno);
	if(destroirTDA(&meuTDA)){
		printf("Erro ao destruir o TDA.\n");
		exit(1);
	}
	printf("Destruicao OK.\n");
	return 0;
}
