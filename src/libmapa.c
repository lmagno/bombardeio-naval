#include <stdio.h>
#include <stdlib.h>
#include "libmatriz.h"

struct MapaTag;
typedef struct MapaTag {
    char **M;
    int m, n;
} Mapa;

Mapa* leia_mapa(){
    FILE *arq;
    Mapa *mapa = (Mapa *)malloc(sizeof(Mapa));
    char **M;
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

    M = aloca_matriz(m, n);

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            fscanf(arq, "%c", &M[i][j]);
        }
    }

    fclose(arq);

    mapa->M = M;
    mapa->m = m;
    mapa->n = n;
    return mapa;
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
    }
}

int escrever_mapa_arquivo(Mapa *mapa){
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
