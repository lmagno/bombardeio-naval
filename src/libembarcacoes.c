#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmapa.h"

#define FALSE 0
#define TRUE  1

/* afunda_destroyer: -Recursão aparentemente OK; -Identação corrigida, serve de protótipo para as outras */
void afunda_destroyer(Mapa mapa, int x_tiro, int y_tiro){
    int i, j;
    char **M;
    M = matriz(mapa);
    if(M[x_tiro][y_tiro] == 'D'){
	M[x_tiro][y_tiro] = '*';
        if(x_tiro > 0)
            i = x_tiro - 1;
        else
            i = 0;
        if(y_tiro > 0)
            j = y_tiro - 1;
        else
            j = 0;

        for(; i <= x_tiro + 1 || i < linhas(mapa); i++)
            for(; j <= y_tiro + 1 || j < colunas(mapa); j++)
                if(M[i][j]=='D')
                    afunda_destroyer(mapa,i,j);
    }
}

void afunda_cruzador(Mapa mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=matriz(mapa);
    if(M[x_tiro][y_tiro] == 'C'){
        M[x_tiro][y_tiro] = '*';
        if(x_tiro > 0)
            i = x_tiro - 1;
        else
            i = 0;
        if(y_tiro > 0)
            j = y_tiro - 1;
        else
            j = 0;
        for(; i <= x_tiro + 1 || i < linhas(mapa); i++)
            for(; j <= y_tiro + 1 || j < colunas(mapa); j++)
                if(M[i][j]=='C')
                    afunda_cruzador(mapa,i,j);
            
        
    }
}
void afunda_porta_aviao(Mapa mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=matriz(mapa);
    if(M[x_tiro][y_tiro] == 'P'){
        M[x_tiro][y_tiro] = '*';
        if(x_tiro > 0)
            i=x_tiro-1;
        else
            i=0;
        if(y_tiro > 0)
            j=y_tiro-1;
        else
            j=0;
        for( ; i <= x_tiro + 1 || i < linhas(mapa); i++)
            for( ; j <= y_tiro + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'P')
                    afunda_porta_aviao(mapa,i,j);
            
        
    }
}

void afunda_hidro_aviao(Mapa mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=matriz(mapa);
    if(M[x_tiro][y_tiro] == 'H'){
        M[x_tiro][y_tiro] = '*';
        if(x_tiro > 0)
            i = x_tiro - 1;
        else
            i = 0;
        if(y_tiro > 0)
            j = y_tiro - 1;
        else
            j = 0;
        for( ; i <= x_tiro + 1 || i < linhas(mapa); i++)
            for( ; j <= y_tiro + 1 || j < colunas(mapa); j++)
                if(M[i][j] == 'H')
                    afunda_hidro_aviao(mapa,i,j);
            
        
    }
}


void posiciona_barco(Mapa mapa){
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

void afunda_embarcacao(MapaTag mapa,int x_tiro,int y_tiro){ /* Obsoleta? */
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

int sorteia(int k){
    r = (int) (1 + (rand()/(RAND_MAX+1.0))*k);
    return r;
}

void coordenadas_tiro(Mapa mapa, int *x_tiro, int *y_tiro){
    int m = colunas(mapa);
    int n = linhas(mapa);

    x_tiro = sorteia(m);
    y_tiro = sorteia(n);
}

/* Incompleta */
void dispara_tiros(Mapa mapa){
    int i;
    int x_tiro, y_tiro;

    for(i = 0; i < 3; i++) {
        coordenadas_tiro(mapa, &x_tiro, &y_tiro);
        
    }
}

char identifica_alvo_atingido(Mapa mapa, int x_tiro, int y_tiro) {
    char **M;
    char alvo_atingido = M[x_tiro][y_tiro];

    M =  matriz(mapa);
    /* Falta escrever no arquivo para cada caso! */

    switch (alvo_atingido){
    case 'D': /* Destroyer: */
        afunda_destroyer(mapa, x_tiro, y_tiro);
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou uma embarcacao!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'C': /* Cruzador: */
        afunda_cruzador(mapa, x_tiro, y_tiro);
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou uma embarcacao!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'P': /* Porta-avião: */
        afunda_porta_aviao(mapa, x_tiro, y_tiro);
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou uma embarcacao!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'H': /* Hidro-avião: */
        afunda_hidro_aviao(mapa, x_tiro, y_tiro);
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou uma embarcacao!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'S': /* Submarino: */
        M[x_tiro][y_tiro] = '*';
        printf("O tiro acertou uma embarcacao!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'B': /* Barco: */
        M[x_tiro][y_tiro] = '!';
        printf("O tiro acertou seu barco!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    case 'T':
        M[x_tiro][y_tiro] = '+';
        printf("O tiro acertou parte do caminho percorrido por seu barco!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    default:
        M[x_tiro][y_tiro] = '=';
        printf("O tiro acertou a agua!\n");
        escreve_mapa_tela(mapa);
        escreve_mapa_arquivo(mapa);
        break;
    }
}
