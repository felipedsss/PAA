/*
Descrição: O objetivo deste exercício é implementar um programa em C que realize as seguintes operações em um vetor de inteiros:

Alocar dinamicamente o vetor com um tamanho especificado.
Preencher o vetor com números aleatórios.
Inverter os elementos do vetor.
Imprimir o vetor original e o vetor invertido.
Passos necessários:

Declaração e implementação da função alocarVetor:

A função alocarVetor deve ser definida como int *.
Ela recebe como parâmetro um inteiro representando o tamanho do vetor a ser alocado.
Dentro da função, aloque dinamicamente um vetor de inteiros com o tamanho especificado.
Retorne o ponteiro para o vetor alocado.
Declaração e implementação da função preencherVetorAleatorio:

A função preencherVetorAleatorio deve ser definida como void.
Ela recebe como parâmetros um ponteiro para inteiro representando o vetor e um inteiro representando o tamanho do vetor.
Dentro da função, use a função rand para gerar números aleatórios e preencher o vetor.
Declaração e implementação da função imprimirVetor:

A função imprimirVetor deve ser definida como void.
Ela recebe como parâmetros um ponteiro para inteiro representando o vetor e um inteiro representando o tamanho do vetor.
Dentro da função, imprima os elementos do vetor na tela.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "invert_array.h"

// Função para alocar dinamicamente um vetor de inteiros
int *alocarVetor(int tamanho) {
    int *vetor = malloc(sizeof(int)*tamanho);
    return vetor;
}

// Função para preencher o vetor com valores aleatórios
void preencherVetor(int *vetor, int tamanho) {
    srand(time(NULL)); // Inicializa uma semente para gerar números aleatórios

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }
}

// Função para imprimir o vetor
void imprimirVetor(int *vetor, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

// Função para inverter os elementos do vetor
void inverterVetor(int *vetor, int tamanho) {
    int temp;
    for (int i = 0; i < tamanho / 2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[tamanho - 1 - i];
        vetor[tamanho - 1 - i] = temp;
    }
}