#include "main.h"

typedef struct Aluno{
    char *nome;
    char *matricula;
    int nota;
} Aluno;

void myprint(void *p) {
    int printInt = *(int *)p;
    printf("%d\n", printInt);

}

void myprintChar(void *p) {
    char printChar = *(char *)p;
    printf("%c\n", printChar);
}

void myprintFloat(void *p) {
    float printFloat = *(float *)p;
    printf("%f\n", printFloat);

}

void printAluno(void *p) {
    Aluno aluno = *(Aluno *)p;
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %s\n", aluno.matricula);
    printf("Nota: %d\n", aluno.nota);
}

int somaFloat(void *dado1, void *dado2, void **soma){
    float floatDado1 = *(float *)dado1;
    float floatDado2 = *(float *)dado2;
    //float SomaAtual = *(float *)soma;
    //printf("SOMA ATUAL: %f SOMANDO %f com %f\n", SomaAtual, floatDado1, floatDado2);
    float floatDado3 = floatDado1 + floatDado2;
    memcpy(soma, &floatDado3, sizeof(float));
    return SUCCESS;
}

int somaChar(void *dado1, void *dado2, void **soma) {
    char charDado1 = *(char *)dado1;
    char charDado2 = *(char *)dado2;
    //char SomaAtual = *(char *)soma;
    //printf("SOMA ATUAL: %c SOMANDO %c com %c\n", SomaAtual, charDado1, charDado2);
    char charDado3 = charDado1 + charDado2;
    memcpy(soma, &charDado3, sizeof(char));
    return SUCCESS;
}
/*
//Esta função não parece ter utilidade
int comparaDados(void *dado1, void *dado2) {
    // TODO
}
*/
int somaDados(void *dado1, void *dado2, void **soma) {
    int intDado1 = *(int *)dado1;
    int intDado2 = *(int *)dado2;
    //int SomaAtual = *(int *)soma;
    //printf("SOMA ATUAL: %d SOMANDO %d com %d\n", SomaAtual, intDado1, intDado2);
    int intDado3 = intDado1 + intDado2;
    memcpy(soma, &intDado3, sizeof(int));
    return SUCCESS; 
}

int somaAlunos(void *dado1, void *dado2, void **soma){
    Aluno aluno1 = *(Aluno *)dado1;
    Aluno aluno2 = *(Aluno *)dado2;

    
    
    //Aluno SomaAtual = *(Aluno *)soma;
    //printf("SOMA ATUAL: %s SOMANDO %s com %s\n", SomaAtual.nome, aluno1.nome, aluno2.nome);
    
    Aluno aluno3;
    aluno3.nome = (char *)malloc(sizeof(char) * (strlen(aluno1.nome) + strlen(aluno2.nome) +1));
    strcpy(aluno3.nome, aluno1.nome);
    strcat(aluno3.nome, aluno2.nome);
    aluno3.matricula = (char *)malloc(sizeof(char) * (strlen(aluno1.matricula) + strlen(aluno2.matricula) +1));
    strcpy(aluno3.matricula, aluno1.matricula);
    strcat(aluno3.matricula, aluno2.matricula);
    aluno3.nota = aluno1.nota + aluno2.nota;
    
    
    memcpy(soma, &aluno3, sizeof(Aluno));
    
    return SUCCESS;
}

int main(int argc, char *argv[]) {
    pDDLL lista = NULL;
    cDDLL (&lista, sizeof(int));
    for (int i = 1; i < 10; i++) {
        printf("%d ", i);
        void *element = &i;
        iEnd(lista,element);
    }
    pOdd(lista, myprint);
    pSum(lista, somaDados, myprint);
    dDDLL (&lista);


    //Testando com chars
    pDDLL listaChar;
    
    cDDLL (&listaChar, sizeof(char));

    char novoChar = 'a';
    for (int i = 1; i < 10; i++) {
        novoChar += 1;
        printf("%c ", novoChar);
        void *element = &novoChar;
        iEnd(listaChar,element);
    }
    pOdd(listaChar, myprintChar);
    pSum(listaChar, somaChar, myprintChar);
    dDDLL (&listaChar);

    //testando com floats
    pDDLL listaFloat;
    
    cDDLL (&listaFloat, sizeof(float));

    float novoFloat = 1.0;
    for (int i = 1; i < 10; i++) {
        novoFloat += 0.1;
        printf("%f ", novoFloat);
        void *element = &novoFloat;
        iEnd(listaFloat,element);
    }
    pOdd(listaFloat, myprintFloat);
    pSum(listaFloat, somaFloat, myprintFloat);
    dDDLL (&listaFloat);

    //testando com structs



    pDDLL listaAluno;
    cDDLL (&listaAluno, sizeof(Aluno));
    
    Aluno novoAlunoA, novoAlunoB, novoAlunoC;
    novoAlunoA.matricula = malloc(sizeof(char)  * 10);
    novoAlunoA.nome = malloc(sizeof(char)  * 100);
    strcpy(novoAlunoA.matricula, "1");
    
    novoAlunoA.nota = 10;
    strcpy(novoAlunoA.nome, "Joao");
    void *element = malloc(sizeof(Aluno));

    memcpy(element, &novoAlunoA, sizeof(Aluno));
    
    iEnd(listaAluno,element);
    

    novoAlunoB.matricula = malloc(sizeof(char)  * 10);
    novoAlunoB.nome = malloc(sizeof(char)  * 100);  
     
    strcpy(novoAlunoB.matricula, "2");
    novoAlunoB.nota = 8;
    strcpy(novoAlunoB.nome, "Maria"); 
    memcpy(element, &novoAlunoB, sizeof(Aluno));
    iEnd(listaAluno, element);
    novoAlunoC.matricula = malloc(sizeof(char)  * 10);
    novoAlunoC.nome = malloc(sizeof(char)  * 100);      
    strcpy(novoAlunoC.matricula, "3");
    novoAlunoC.nota = 9;
    strcpy(novoAlunoC.nome, "Jose"); 
    memcpy(element, &novoAlunoC, sizeof(Aluno));
    iEnd(listaAluno, element);
    pOdd(listaAluno, printAluno);
    pSum(listaAluno, somaAlunos, printAluno);
    dDDLL(&listaAluno);
    free(novoAlunoA.matricula);
    free(novoAlunoA.nome);
    free(novoAlunoB.matricula);
    free(novoAlunoB.nome);
    free(novoAlunoC.matricula);
    free(novoAlunoC.nome);    
    
    free(element);
    
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    return 0;
}
