#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afunda_destroyer(MapaTag mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=mapa ->M;
    if(M[x_tiro][y_tiro]=='D')
        M[x_tiro][y_tiro]='*';
    if(x_tiro>0)
        i=x_tiro-1;
    else
        i=0;
    if(y_tiro>0)
        j=y_tiro-1;
    else
        j=0;
    for( ; i<=x_tiro+1||i<mapa->m ; i++){
        for( ; j<=y_tiro+1||j<mapa->n ; j++){
            if(M[i][j]=='D')
                afunda_destroyer(mapa,i,j);
        }
    }
    mapa->M = M;
}

void afunda_cruzador(MapaTag mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=mapa ->M;
    if(M[x_tiro][y_tiro]=='C')
        M[x_tiro][y_tiro]='*';
    if(x_tiro>0)
        i=x_tiro-1;
    else
        i=0;
    if(y_tiro>0)
        j=y_tiro-1;
    else
        j=0;
    for( ; i<=x_tiro+1||i<mapa->m ; i++){
        for( ; j<=y_tiro+1||j<mapa->n ; j++){
            if(M[i][j]=='C')
                afunda_destroyer(mapa,i,j);
        }
    }
    mapa->M = M;
}

void afunda_porta_aviao(MapaTag mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=mapa ->M;
    if(M[x_tiro][y_tiro]=='P')
        M[x_tiro][y_tiro]='*';
    if(x_tiro>0)
        i=x_tiro-1;
    else
        i=0;
    if(y_tiro>0)
        j=y_tiro-1;
    else
        j=0;
    for( ; i<=x_tiro+1||i<mapa->m ; i++){
        for( ; j<=y_tiro+1||j<mapa->n ; j++){
            if(M[i][j]=='P')
                afunda_destroyer(mapa,i,j);
        }
    }
    mapa->M = M;
}

void afunda_hidro_aviao(MapaTag mapa,int x_tiro,int y_tiro){
    int i,j;
    char **M;
    M=mapa ->M;
    if(M[x_tiro][y_tiro]=='H')
        M[x_tiro][y_tiro]='*';
    if(x_tiro>0)
        i=x_tiro-1;
    else
        i=0;
    if(y_tiro>0)
        j=y_tiro-1;
    else
        j=0;
    for( ; i<=x_tiro+1||i<mapa->m ; i++){
        for( ; j<=y_tiro+1||j<mapa->n ; j++){
            if(M[i][j]=='H')
                afunda_destroyer(mapa,i,j);
        }
    }
    mapa->M = M;
}

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
