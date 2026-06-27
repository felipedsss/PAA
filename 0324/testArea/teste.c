#include <stdio.h>

int letipo(char *entrada){
    if (!(entrada[0] == '-' || (entrada[0] >= '0' && entrada[0] <= '9'))) {
        return 2; //caso o primeiro caractere não seja o sinal negativo ou não seja numerico é uma string
    }else{
        int numpontos=0, stringCount = 1, foundtype = 0;
        while (entrada[stringCount] != '\0' && entrada[stringCount] != '\n'){
            printf("%c", entrada[stringCount]);
            if (entrada[stringCount] < '0' || entrada[stringCount] > '9') {
                if (entrada[stringCount] == '.') {
                    if (numpontos == 0) {
                        printf("EUREKA");
                        numpontos = 1; //apenas um ponto decimal e não é string -> é float
                        foundtype=1;
                    } else {
                        return 2;
                        // Mais de um ponto decimal encontrado, é string
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

    int main (){
        char *entrada;
        printf("Digite uma entrada, digite M para sair\n");
        while (*entrada != 'M'){
            scanf("%s",entrada);
            printf("\n%s %d\n", entrada, letipo(entrada));

        }
    }