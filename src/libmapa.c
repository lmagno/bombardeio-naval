#include <stdio.h>
#include <stdlib.h>
#include "libutils.h"
#include "libmapa.h"


// Tipo Mapa para guardar a matriz que representa o estado de um jogo
// e suas dimensões mxn.
// À struct é dado o nome de MapaTag somente para permitir que a
// declaração de Mapa seja feita no header desta biblioteca sem que
// se exporte a struct em si.
struct MapaTag {
    char **M;
    int m, n;
};
typedef struct MapaTag Mapa;

// Recebe:
//     Mapa *mapa: ponteiro em que será gravado o mapa lido.
//     char *nome: string com o nome de um arquivo que contém um mapa
//                 no formato especificado.
// Retorna:
//     int 0: em caso de sucesso.
//     int 1: caso não consiga abrir o arquivo
//     int 2: caso o mapa esteja em formato errado.
int leia_mapa_arquivo(Mapa *mapa, char *nome){
    mapa = (Mapa *)malloc(sizeof(Mapa));
    FILE *arq;
    char **M, c;
    int i, j, m, n;

    arq = fopen(nome, "r");
    if (arq == NULL) {
        return 1;
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
            // Mensagens de erro ficam pro futuro
            // printf("A linha %d tem %d elementos, equanto se esperava %d!\n", i+1, j, n);
            return(2);
        }

        if (c == '|') descarta_resto_linha(arq);
    }

    mapa->M = M;
    mapa->m = m;
    mapa->n = n;
    fclose(arq);
    return 0;
}

// Recebe o ponteiro para um Mapa e imprime sua representação para a tela,
// ocultando as casas que o usuário não deve ver.
void escreva_mapa_tela(Mapa *mapa){
    int i , j;
    char **M = matriz(mapa);
    int m = linhas(mapa),
        n = colunas(mapa);

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

// Recebe o nome de um arquivo e o ponteiro para um Mapa e concatena
// sua representação ao final desse arquivo.
// Retorna:
//     0: em caso de sucesso
//     1: caso não consiga abrir o arquivo (erro)
int escreva_mapa_arquivo(char *nome, Mapa *mapa){
    char **M = matriz(mapa);
    int m = linhas(mapa),
        n = colunas(mapa);
    FILE *arq;
    int i, j;

    arq = fopen(nome, "a");
    if (arq == NULL) {
        printf("Arquivo não pôde ser aberto! :/\n");
        return 1;
    }

    fprintf(arq, "\n");
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
          fprintf(arq, "%c ", M[i][j]);
        }
        printf("\n");
    }

    fclose(arq);
    return 0;
}

// Recebe o ponteiro para um Mapa e libera a matriz nele contida,
// além de seu próprio espaço alocado.
void libera_mapa(Mapa *mapa) {
    libera_matriz(mapa->M, mapa->m);
    free(mapa);
}

// Recebe o ponteiro para um Mapa e retorna o ponteiro para a matriz
// nele contida.
char** matriz(Mapa *mapa) {
    return mapa->M;
}

// Recebe o ponteiro para um mapa e retorna o número de linhas que a matriz
// nele contida tem.
int linhas(Mapa *mapa) {
    return mapa->m;
}

// Recebe o ponteiro para um mapa e retorna o número de colunas que a matriz
// nele contida tem.
int colunas(Mapa *mapa) {
    return mapa->n;
}
