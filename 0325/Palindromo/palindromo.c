#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verificarPalindromo(char *str) {
    int i = 0, j = strlen(str) - 1;
    //contador i varrerá no sentido direto enquanto j varrerá no sentido inverso
    while (i <= j) {
        // Comparação dos códigos ASCII das letras maiúsculas e minúsculas
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            i++; //Se a posição i contem caracteres estranhos, desconsiderar
        else if (!((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')))
            j--;//Se a posição j contem caracteres estranhos, desconsiderar
        else if (str[i] == str[j] || str[i] - 'A' + 'a' == str[j] || str[j] - 'A' + 'a' == str[i]) {
            i++;
            j--;// a subtração de 'A' coma soma de 'a' é utilizada para extrair o offset entre a maíúscula e a minúscula
        } else
            return false;
    }
    return true;
}