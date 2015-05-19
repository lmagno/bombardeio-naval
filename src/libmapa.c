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

// Recebe o ponteiro para um arquivo em que esteja especificado um mapa
// mxn para o jogo e retorna um ponteiro para o Mapa lido.
// Termina o programa com erro se o formato não estiver correto.
Mapa* leia_mapa_arquivo(FILE *arq){
    Mapa *mapa = (Mapa *)malloc(sizeof(Mapa));
    char **M, c;
    int i, j, m, n;

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


    mapa->M = M;
    mapa->m = m;
    mapa->n = n;
    return mapa;
}

// Pede que o usuário entre com o nome de um arquivo até que este seja aberto
// com sucesso. Faz a leitura do mapa nele descrito e o retorna.
Mapa* leia_mapa_prompt(){
    FILE *arq;
    char nome[50];
    Mapa *mapa;

    printf("Entre com o nome do arquivo que contém o mapa: ");
    scanf("%s", nome);
    arq = fopen(nome, "r");

    while (arq == NULL) {
        printf("Arquivo não encontrado, entre com o nome de um arquivo válido: ");
        scanf("%s", nome);
        arq = fopen(nome, "r");
    }

    mapa = leia_mapa_arquivo(arq);

    fclose(arq);
    return mapa;
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
