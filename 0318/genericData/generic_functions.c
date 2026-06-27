#include "generic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

int identificarTipo(const char *entrada) {
    int numpontos = 0;
    
    if (!(entrada[0] == '-' || (entrada[0] >= '0' && entrada[0] <= '9'))) {
        return 2; // Não é um número válido
    }
    
    for (int count = 1; entrada[count] != '\0'; count++) {
        if (entrada[count] < '0' || entrada[count] > '9') {
            if (entrada[count] == '.') {
                if (numpontos == 0) {
                    numpontos = 1;
                } else {
                    return 2; // Mais de um ponto decimal encontrado
                }
            } else {
                return 2; // Caractere inválido encontrado
            }
        }
    }
    
    if (numpontos == 1) {
        return 1; // É um float
    }
    
    return 0; // É um inteiro
}

int readGenericData(struct GenericData *newData, int *dataSize) {
	// lê o dado genérico da entrada padrão (stdin)
	char *entrada = (char *)malloc(100 * sizeof(char));
    if (scanf("%99s", entrada) != 1) {
        free(entrada);
        return 1; // Falha ao ler a entrada
    }

	// armazena no vetor alocado na memória heap
	newData->type = identificarTipo(entrada);
    switch(newData->type) {
        case 0: {
            int *intPtr = (int *)malloc(sizeof(int)); 
            *intPtr = atoi(entrada); 
            newData->data = (void *)intPtr; 
            break;
        }
        case 1: {
            float *floatPtr = (float *)malloc(sizeof(float)); 
            *floatPtr = atof(entrada); 
            newData->data = (void *)floatPtr;
            break;
        }
        case 2: 
            newData->data = (void *)entrada;
            break;
    }
	free(entrada);
	(*dataSize)++;
	
	return 0;
}

int printGenericData(struct GenericData *newData, int dataSize) {
	
	printf("Dados inseridos:\n");
	int currentType = -1;
	for (int i = 0; i < dataSize; i++){
		
			switch (newData[i].type){
			case 0:
			    if (currentType != 0) printf("int ");
				printf("%d ", *((int *)newData[i].data));
				currentType = 0;
				break;
			case 1: 
			    if (currentType != 1) printf("float ");
				printf("%.1f ", *((float *)newData[i].data));
				currentType = 1;
				break;
			case 2: 
				if (currentType != 2) printf("string ");
				printf("%s ", (char *)newData[i].data);
				currentType = 2;
				break;
		}
	}
	free(newData);
	// identifica o tipo do dado (int, string, float)
	// imprime o dado na tela na seguinte ordem: int's, float's e string's 
	// entre os dados de cada tipo, a ordem é a de leitura
	// retorna 0, se sucesso, e 1, se fracasso;
	return 0;
}
