#include "generic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX_DATA_SIZE = 5;

int letipo(char *entrada){
    if (!(entrada[0] == '-' || (entrada[0] >= '0' && entrada[0] <= '9'))) {
        return 2; //caso o primeiro caractere não seja o sinal negativo ou não seja numerico é uma string
    }else{
        int numpontos=0, stringCount = 1, foundtype = 0;
        while (entrada[stringCount] != '\0' && entrada[stringCount] != '\n'){
            
            if (entrada[stringCount] < '0' || entrada[stringCount] > '9') {
                if (entrada[stringCount] == '.') {
                    if (numpontos == 0) {
                        numpontos = 1; //apenas um ponto decimal e não é string -> é float
                        foundtype=1;
                    } else {
                        return 2; // Mais de um ponto decimal encontrado, é string
                    }
                } else {
                    return 2; // Caracter não decimal e não ponto -> é string
                }
            }
            stringCount++; // próximo caracter
        }
        return foundtype;
    }
}

int readGenericData(struct GenericData *data, int *dataSize) {
        if (*dataSize>MAX_SIZE){
            printf("Ultrapassou o tamanho maximo do vetor.");
            return 1;
        }
        char *entrada = malloc(100 * sizeof(char));
        scanf("%s", entrada);
        data[*dataSize].type = letipo(entrada);
        
        switch (data[*dataSize].type) {
            case 0:
                data[*dataSize].data = malloc(sizeof(int));
                *(int *)data[*dataSize].data = atoi(entrada);
                break;
            case 1:
                data[*dataSize].data = malloc(sizeof(float));
                *(float *)data[*dataSize].data = atof(entrada);
                
                break;
            case 2:
                data[*dataSize].data = malloc(strlen(entrada) + 1);
                strcpy((char *)data[*dataSize].data, entrada);
                break;
        }
        free(entrada);

        (*dataSize)++;
  
        

    return 0;    
}

int printGenericData(struct GenericData *data, int dataSize) {
   
    int currentType =  -1;
    int doneInt = 0;
    
    for (int i = 0; i < dataSize; i++) {
        
        
        switch (data[i].type) {
            case 0: // Int
                if (currentType != 0 && doneInt ==0) printf("int ");
                currentType = 0;
                doneInt = 1;
                printf("%d ", *(int *)data[i].data);
                break;
            case 1: // Float
                if (currentType != 1) printf("float ");
                currentType = 1;
                printf("%.1f ", *(float *)data[i].data);
                break;
            case 2: // String
                if (currentType != 2) printf("string ");
                currentType = 2;
                printf("%s ", (char *)data[i].data);
                break;
        }
    }
    
    //free(data->data);
    return 0;
return 0;
}
