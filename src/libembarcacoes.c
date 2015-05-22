#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libutils.h"
#include "libmapa.h"
#include "libembarcacoes.h"

#define FALSE 0
#define TRUE  1

/* afunda_destroyer: Aparentemente OK, necessita de testes;
-Identação corrigida, serve de protótipo para as outras */

/* d: distância do tiro em relação à casa a ser afetada pela função */
void afunda_destroyer(Mapa *mapa, int x, int y, int d){
    int i, j,i_in,j_in;
    char **M;
    M = matriz(mapa);

    if(M[y][x] == 'D' || d == 0){

        M[y][x] = '*';

        if(x > 0)
            i_in = x - 1;
        else
            i_in = 0;
        if(y > 0)
            j_in = y - 1;
        else
            j_in = 0;

        for(i = i_in; i <= y + 1 || i < linhas(mapa); i++)
            for(j = j_in; j <= x + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'D')
                    afunda_destroyer(mapa,i,j,d+1);
    }
}

void afunda_cruzador(Mapa *mapa, int x, int y, int d){
    int i, j,i_in,j_in;
    char **M;
    M = matriz(mapa);

    if(M[y][x] == 'C' || d == 0){

        M[y][x] = '*';

        if(x > 0)
            i_in = x - 1;
        else
            i_in = 0;
        if(y > 0)
            j_in = y - 1;
        else
            j_in = 0;

        for(i = i_in; i <= y + 1 || i < linhas(mapa); i++)
            for(j = j_in; j <= x + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'C')
                    afunda_cruzador(mapa,i,j,d+1);
    }
}

void afunda_porta_aviao(Mapa *mapa, int x, int y, int d){
    int i, j,i_in,j_in;
    char **M;
    M = matriz(mapa);

    if(M[y][x] == 'P' || d == 0){

        M[y][x] = '*';

        if(x > 0)
            i_in = x - 1;
        else
            i_in = 0;
        if(y > 0)
            j_in = y - 1;
        else
            j_in = 0;

        for(i=i_in; i <= y + 1 || i < linhas(mapa); i++)
            for(j=j_in; j <= x + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'P')
                    afunda_porta_aviao(mapa,i,j,d+1);
    }
}

void afunda_hidro_aviao(Mapa *mapa, int x, int y, int d){
    int i, j,i_in,j_in;
    char **M;
    M = matriz(mapa);

    if(M[y][x] == 'H' || d == 0){

        M[y][x] = '*';

        if(x > 0)
            i_in = x - 1;
        else
            i_in = 0;
        if(y > 0)
            j_in = y - 1;
        else
            j_in = 0;

        for(i = i_in; i <= y + 1 || i < linhas(mapa); i++)
            for(j = j_in; j <= x + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'H')
                    afunda_hidro_aviao(mapa,i,j,d+1);
    }
}

/* sorteia - Retorna um valor aleatório no intervalo 0...k-1 */
int sorteia(int k){
    int r;
    r = rand() % k;
    return r;
}

/* coordenadas tiro - Determina as coordenadas de um tiro aleatório;
   Retorna os valores em x_tiro e y_tiro */
void coordenadas_tiro(Mapa *mapa, int *x_tiro, int *y_tiro){
    int m = colunas(mapa);
    int n = linhas(mapa);

    *x_tiro = sorteia(m);
    *y_tiro = sorteia(n);
}

/* identifica_alvo_atingido - Imprime as coordenadas de um tiro e a mensagem correspondente ao
efeito desse tiro; Retorna o tipo de embarcação atingido (conforme convenção do mapa). */
char identifica_alvo_atingido(Mapa *mapa, int x_tiro, int y_tiro, char* arquivo) {
    char **M;
    char alvo_atingido;

    M =  matriz(mapa);
    alvo_atingido = M[y_tiro][x_tiro];

    printf("Tiro em x = %d e y = %d!\n", x_tiro, y_tiro);

    switch (alvo_atingido){
    case 'D': /* Destroyer: */
        M[y_tiro][x_tiro] = '*';
        printf("O tiro acertou um destroyer!\n");
        anexa_arquivo(arquivo,"O tiro acertou um destroyer!\n");
        break;
    case 'C': /* Cruzador: */
        M[y_tiro][x_tiro] = '*';
        printf("O tiro acertou um cruzador!\n");
        anexa_arquivo(arquivo,"O tiro acertou um cruzador!\n");
        break;
    case 'P': /* Porta-avião: */
        M[y_tiro][x_tiro] = '*';
        printf("O tiro acertou um porta-aviões!\n");
        anexa_arquivo(arquivo,"O tiro acertou um porta-aviões!\n");
        break;
    case 'H': /* Hidro-avião: */
        M[y_tiro][x_tiro] = '*';
        printf("O tiro acertou um hidro-avião!\n");
        anexa_arquivo(arquivo,"O tiro acertou um hidro-avião!\n");
        break;
    case 'S': /* Submarino: */
        M[y_tiro][x_tiro] = '*';
        printf("O tiro acertou um submarino!\n");
        anexa_arquivo(arquivo,"O tiro acertou um submarino!\n");
        break;
    case 'B': /* Barco: */
        M[y_tiro][x_tiro] = '!';
        printf("O tiro acertou seu barco!\n");
        anexa_arquivo(arquivo,"O tiro acertou seu barco!\n");
        break;
    case 'T':
        M[y_tiro][x_tiro] = '+';
        printf("O tiro acertou parte do caminho percorrido por seu barco!\n");
        anexa_arquivo(arquivo,"O tiro acertou parte do caminho percorrido por seu barco!\n");
        break;
    default:
        M[y_tiro][x_tiro] = '=';
        printf("O tiro acertou a água!\n");
        anexa_arquivo(arquivo,"O tiro acertou a água!\n");
        break;
    }

    return alvo_atingido;
}

/* dispara_tiros - Dispara 3 tiros, imprime as mensagens correspondentes aos efeitos dos
tiros e atualiza a matriz; Retorna FALSE (0) caso o jogo continue,
retorna TURE (1) caso o jogo termine. */
int dispara_tiros(Mapa *mapa, char *arquivo){
    int i;
    int x_tiro, y_tiro;
    int alvo_atingido;
    int fim_de_jogo = FALSE;

    for(i = 0; i < 3 && !fim_de_jogo; i++) {

        coordenadas_tiro(mapa, &x_tiro, &y_tiro);
        alvo_atingido = identifica_alvo_atingido(mapa, x_tiro, y_tiro, arquivo);

        switch(alvo_atingido){
        case 'D':
            afunda_destroyer(mapa,x_tiro,y_tiro,0);
            break;
        case 'C':
            afunda_cruzador(mapa,x_tiro,y_tiro,0);
            break;
        case 'P':
            afunda_porta_aviao(mapa,x_tiro,y_tiro,0);
            break;
        case 'H':
            afunda_hidro_aviao(mapa,x_tiro,y_tiro,0);
            break;
        case 'B':
            fim_de_jogo = TRUE;
            break;
        default:
            break;
        }

        escreva_mapa_tela(mapa);
        escreva_mapa_arquivo(arquivo, mapa);
    }

    return fim_de_jogo;
}
