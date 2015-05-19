#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmapa.h"

#define FALSE 0
#define TRUE  1

/* afunda_destroyer: Aparentemente OK, necessita de testes; 
-Identação corrigida, serve de protótipo para as outras */

/* d: distância do tiro em relação à casa a ser afetada pela função */
void afunda_destroyer(Mapa *mapa, int x, int y, int d){
    int i, j;
    char **M;
    M = matriz(mapa);

    if(M[x][y] == 'D' || d == 0){

        M[x][y] = '*';

        if(x > 0)
            i = x - 1;
        else
            i = 0;
        if(y > 0)
            j = y - 1;
        else
            j = 0;

        for(; i <= x + 1 || i < linhas(mapa); i++)
            for(; j <= y + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'D')
                    afunda_destroyer(mapa,i,j,d+1);
    }
}

void afunda_cruzador(Mapa *mapa, int x, int y, int d){
    int i, j;
    char **M;
    M = matriz(mapa);

    if(M[x][y] == 'C' || d == 0){

        M[x][y] = '*';

        if(x > 0)
            i = x - 1;
        else
            i = 0;
        if(y > 0)
            j = y - 1;
        else
            j = 0;

        for(; i <= x + 1 || i < linhas(mapa); i++)
            for(; j <= y + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'C')
                    afunda_cruzador(mapa,i,j,d+1);
    }
}

void afunda_porta_aviao(Mapa *mapa, int x, int y, int d){
    int i, j;
    char **M;
    M = matriz(mapa);

    if(M[x][y] == 'P' || d == 0){

        M[x][y] = '*';

        if(x > 0)
            i = x - 1;
        else
            i = 0;
        if(y > 0)
            j = y - 1;
        else
            j = 0;

        for(; i <= x + 1 || i < linhas(mapa); i++)
            for(; j <= y + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'P')
                    afunda_porta_aviao(mapa,i,j,d+1);
    }
}

void afunda_hidro_aviao(Mapa *mapa, int x, int y, int d){
    int i, j;
    char **M;
    M = matriz(mapa);

    if(M[x][y] == 'H' || d == 0){

        M[x][y] = '*';

        if(x > 0)
            i = x - 1;
        else
            i = 0;
        if(y > 0)
            j = y - 1;
        else
            j = 0;

        for(; i <= x + 1 || i < linhas(mapa); i++)
            for(; j <= y + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'H')
                    afunda_hidro_aviao(mapa,i,j,d+1);
    }
}

/* Isso não deveria estar aqui */
/*
void posiciona_barco(Mapa *mapa){
    int y_barco;
    int posicionou = FALSE;
    char **M;
    M = matriz(mapa);
    while(!posicionou){
        y_barco = sorteia(linhas(mapa));
        if(M[0][y_barco] == '.'){
            M[0][y_barco] = 'B';
            posicionou = TRUE;
        }
    }
}
*/

/* Obsoleta? */
/*
void afunda_embarcacao(MapaTag mapa,int x_tiro,int y_tiro){  
    char** M;
    M=mapa->M;
    if(M[x_tiro][y_tiro]=='D')
        afunda_destroyer(M,x_tiro,y_tiro);
    if(M[x_tiro][y_tiro]=='C')
        afunda_cruzador(M,x_tiro,y_tiro);
    if(M[x_tiro][y_tiro]=='P')
        afunda_porta_aviao(M,x_tiro,y_tiro);
    if(M[x_tiro][y_tiro]=='H')
        afunda_hidro_aviao(M,x_tiro,y_tiro);
    mapa->=M;
}
*/

/* sorteia - Retorna um valor aleatório no intervalo 1...k */
int sorteia(int k){
    r = (int) (1 + (rand()/(RAND_MAX+1.0))*k);
    return r;
}

/* coordenadas tiro - Determina as coordenadas de um tiro aleatório; 
   Retorna os valores em x_tiro e y_tiro */
void coordenadas_tiro(Mapa *mapa, int *x_tiro, int *y_tiro){
    int m = colunas(mapa);
    int n = linhas(mapa);

    x_tiro = sorteia(m);
    y_tiro = sorteia(n);
}

/* identifica_alvo_atingido - Imprime as coordenadas de um tiro e a mensagem correspondente ao
efeito desse tiro; Retorna o tipo de embarcação atingido (conforme convenção do mapa). */
/* Falta escrever no arquivo as mensagens de cada caso */
char identifica_alvo_atingido(Mapa *mapa, int x_tiro, int y_tiro) {
    char **M;
    char alvo_atingido;

    M =  matriz(mapa);
    alvo_atingido = M[x_tiro][y_tiro];

    printf("Tiro em x = %d e y = %d!\n", x_tiro, y_tiro);

    /* Falta escrever no arquivo para cada caso! */

    switch (alvo_atingido){
    case 'D': /* Destroyer: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou um destroyer!\n");
        break;
    case 'C': /* Cruzador: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou um cruzador!\n");
        break;
    case 'P': /* Porta-avião: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou um porta-aviões!\n");
        break;
    case 'H': /* Hidro-avião: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou um hidro-avião!\n");
        break;
    case 'S': /* Submarino: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou um submarino!\n");
        break;
    case 'B': /* Barco: */
        M[x_tiro][y_tiro] = '!';
        printf("O tiro acertou seu barco!\n");
        break;
    case 'T':
        M[x_tiro][y_tiro] = '+';
        printf("O tiro acertou parte do caminho percorrido por seu barco!\n");
        break;
    default:
        M[x_tiro][y_tiro] = '=';
        printf("O tiro acertou a água!\n");
        break;
    }

    return alvo_atingido;
}

/* dispara_tiros - Dispara 3 tiros, imprime as mensagens correspondentes aos efeitos dos
tiros e atualiza a matriz; Retorna FALSE (0) caso o jogo continue, 
retorna TURE (1) caso o jogo termine. */
int dispara_tiros(Mapa *mapa){
    int i;
    int x_tiro, y_tiro;
    int fim_de_jogo = FALSE;

    for(i = 0; i < 3 && !fim_de_jogo; i++) {

        coordenadas_tiro(mapa, &x_tiro, &y_tiro);
        alvo_atingido = identifica_alvo_atingido(mapa, x_tiro, y_tiro);

        switch(alvo_atingido){
        case 'D':
            afunda_destroyer(mapa,x_tiro,y_tiro,0);
            break;
        case 'C':
            afunda_cruzador(mapa,x_tiro,y_tiro);
            break;
        case 'P':
            afunda_porta_aviao(mapa,x_tiro,y_tiro);
            break;
        case 'H':
            afunda_hidro_aviao(mapa,x_tiro,y_tiro);
            break;
        case 'B':
            fim_de_jogo = TRUE;
            break;
        default:
            break;
        }

        escreva_mapa_tela(mapa);
        /*escreva_mapa_arquivo(mapa, arquivo);*/
    }

    return fim_de_jogo;
}
