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
