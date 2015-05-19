#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void posiciona_barco(char **M){
  char boolean=0;
  int i,posicao;
  while(boolean==0){
    printf("digite a posição inicial do barco");
    scanf("%d",&posicao);
    if(M[0][posicao]=='.'){
      M[0][posicao]='B';
      boolean=1;
    }
    else
      printf("posicao nao disponivel");
  }
}

void rema_barco(Mapa mapa, int *x_B, int *y_B){
    char ** M = matriz(mapa);
    char movimento;
    int x_barco,y_barco,moveu = FALSE;
    x_barco = *x_B;
    y_barco = *y_B;
    scanf("%c",&movimento);
    if(movimento == 'c' && y_barco > 0){
	if(M[x_barco][y_barco - 1] != 'D' || \
	   M[x_barco][y_barco - 1] != 'S' || \
	   M[x_barco][y_barco - 1] != 'H' || \
	   M[x_barco][y_barco - 1] != 'P' || \
	   M[x_barco][y_barco - 1] != 'C' ){
	    M[x_barco][y_barco] = 'T';
	    M[x_barco][y_barco - 1] = 'B';
	    moveu = TRUE;
	    y_barco--;
	}
    }    
    if(movimento == 'b' && y_barco < linhas(mapa)){
	if(M[x_barco][y_barco + 1] != 'D' || \
	   M[x_barco][y_barco + 1] != 'S' || \
	   M[x_barco][y_barco + 1] != 'H' || \
	   M[x_barco][y_barco + 1] != 'P' || \
	   M[x_barco][y_barco + 1] != 'C' ){
	    M[x_barco][y_barco] = 'T';
	    M[x_barco][y_barco + 1] = 'B';
	    moveu = TRUE;
	    y_barco++;
	}
    }    
    if(movimento == 'e' && x_barco > 0){
	if(M[x_barco - 1][y_barco] != 'D' || \
	   M[x_barco - 1][y_barco] != 'S' || \
	   M[x_barco - 1][y_barco] != 'H' || \
	   M[x_barco - 1][y_barco] != 'P' || \
	   M[x_barco - 1][y_barco] != 'C' ){
	    M[x_barco][y_barco] = 'T';
	    M[x_barco - 1][y_barco] = 'B';
	    moveu = TRUE;
	    x_barco--;
	}
    }    
    if(movimento == 'd' && x_barco < colunas(mapa)){
	if(M[x_barco + 1][y_barco] != 'D' || \
	   M[x_barco + 1][y_barco] != 'S' || \
	   M[x_barco + 1][y_barco] != 'H' || \
	   M[x_barco + 1][y_barco] != 'P' || \
	   M[x_barco + 1][y_barco] != 'C' ){
	    M[x_barco][y_barco] = 'T';
	    M[x_barco + 1][y_barco] = 'B';
	    moveu = TRUE;
	    x_barco++;
	}
    }    
    *x_B = x_barco;
    *y_B = y_barco;
}
