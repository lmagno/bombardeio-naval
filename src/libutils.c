#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libutils.h"

// Aloca uma matriz char mxn
// e retorna seu ponteiro
char** aloca_matriz(int m,int n){
    char **M;
    int i;
    M=(char **)malloc(m*sizeof(char *));
    for(i=0 ; i<m;i++){
        M[i]=(char*)malloc(n*sizeof(char));
    }
    return M;
}

// Recebe o ponteiro para uma matriz char M
// e libera toda a memória alocada a ela
void libera_matriz(char **M, int m){
    int i;

    for(i = 0 ; i < m ; i++){
        free(M[i]);
    }
    free(M);
}

// Recebe o ponteiro para uma matriz char mxn
// e imprime todo seu conteúdo para a STDOUT
void escreva_matriz_tela(char **M, int m, int n){
    int i, j;

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%c", M[i][j]);
        }
        printf("\n");
    }
}

// Recebe o ponteiro para um arquivo e avança seu buffer até uma
// quebra de linha.
void descarta_resto_linha(FILE *arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c != '\n');
}

// Recebe o ponteiro para um arquivo e avança seu buffer até o primeiro
// caracter que não seja whitespace, retornando ele em seguida.
char prox_elem(FILE *arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c == ' ' || c == '\t');

    return c;
}

// Recebe o nome de um arquivo e uma string e a concatena
// ao final desse arquivo.
// Retorna:
//     0: em caso de sucesso
//     1: caso não consiga abrir o arquivo (erro)
int anexa_arquivo(char *nome, char *str) {
    FILE *arq;

    arq = fopen(nome, "a");
    if (arq == NULL) {
        printf("Arquivo não pôde ser aberto! :/\n");
        return 1;
    }

    fprintf(arq, "%s", str);
    fclose(arq);
    return 0;
}
