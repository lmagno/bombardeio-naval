#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** aloca_matriz(int m,int n){
    char** M;
    int i;
    M=(char **)malloc(m*sizeof(char *));
    for(i=0 ; i<m;i++){
        M[i]=(char*)malloc(n*sizeof(char));
    }
    return M;
}

void libera_matriz(char **M, int m){
    int i;

    for(i = 0 ; i < m ; i++){
        free(M[i]);
    }
    free(M);
}

int leia_matriz(char *nome, char** M, int *m, int *n){
    FILE *mapa;
    int linhas, colunas, i, j;

    mapa = fopen(nome,"r");
    if(mapa == NULL){
        printf("Arquivo não encontrado!");
        return 1;
    }

    fscanf(mapa,"%d",&linhas);
    fscanf(mapa,"%d",&colunas);
    M = aloca_matriz(linhas,colunas);

    for(i = 0 ; i < linhas ; i++){
        for(j = 0 ; j < colunas ; j++){
            fscanf(mapa, "%c", &M[i][j]);
        }
    }

    fclose(mapa);
    *m = linhas;
    *n = colunas;
    return 0;
}

void escreva_matriz_tela(char **M, int m, int n){
    int i, j;

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%c", M[i][j]);
        }
        printf("\n");
    }
}
