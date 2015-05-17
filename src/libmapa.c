#include <stdio.h>
#include <stdlib.h>
#include "libmatriz.h"

void descarta_resto_linha(FILE *arq);
char prox_elem(arq);


struct MapaTag {
    char **M;
    int m, n;
};
typedef struct MapaTag Mapa;

Mapa* leia_mapa(){
    FILE *arq;
    Mapa *mapa = (Mapa *)malloc(sizeof(Mapa));
    char **M, c;
    char nome[50];
    int i, j, m, n;

    printf("Entre com o nome do arquivo que contém o mapa: ");
    scanf("%s", nome);
    arq = fopen(nome, "r");

    while (arq == NULL) {
        printf("Arquivo não encontrado, entre com o nome de um arquivo válido: ");
        scanf("%s", nome);
        arq = fopen(nome, "r");
    }

    fscanf(arq, "%d", &m);
    fscanf(arq, "%d", &n);

    descarta_resto_linha(arq);

    M = aloca_matriz(m, n);

    for(i = 0 ; i < m ; i++){
        j = 0;
        c = prox_elem(arq);
        while (c != '|' && c != '\n') {
            M[i][j] = c;
            j++;

            c = prox_elem(arq);
        }
        if (j != n) {
            printf("A linha %d tem %d elementos, equanto se esperava %d!\n", i+1, j, n);
            exit(EXIT_FAILURE);
        }

        if (c == '|') descarta_resto_linha(arq);
    }

    fclose(arq);

    mapa->M = M;
    mapa->m = m;
    mapa->n = n;
    return mapa;
}

void descarta_resto_linha(FILE *arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c != '\n');
}

char prox_elem(arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c == ' ' || c == '\t');

    return c;
}

void escreva_mapa_tela(Mapa *mapa){
    int i , j;
    char **M = mapa->M;
    int m = mapa->m,
        n = mapa->n;

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            if(M[i][j] == '*' || \
               M[i][j] == '!' || \
               M[i][j] == '=' || \
               M[i][j] == '+' || \
               M[i][j] == 'B' || \
               M[i][j] == 'T')
                printf("%c", M[i][j]);
            else
                printf("-");
        }
        printf("\n");
    }
}

int escreva_mapa_arquivo(Mapa *mapa){
    char nome[50];
    char **M = mapa->M;
    int m = mapa->m,
        n = mapa->n;
    FILE *arq;
    int i, j;

    printf("Entre com o nome do arquivo: ");
    scanf("%s", nome);
    arq = fopen(nome,"w");
    if (arq == NULL) {
        printf("Arquivo não pôde ser criado. :/\n");
        return 1;
    }

    fprintf(arq, "%d %d\n", m, n);

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
          fprintf(arq, "%d ", M[i][j]);
        }
        printf("\n");
    }

    fclose(arq);
    return 0;
}

void libera_mapa(Mapa *mapa) {
    libera_matriz(mapa->M, mapa->m);
    free(mapa);
}

char** matriz(Mapa *mapa) {
    return mapa->M;
}

int linhas(Mapa *mapa) {
    return mapa->m;
}

int colunas(Mapa *mapa) {
    return mapa->n;
}
