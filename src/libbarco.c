#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libutils.h"
#include "libmapa.h"
#include "libbarco.h"

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


char rema_barco(char **M,int linhas,int colunas){
  int i,j;
  char movimento,moveu=0;
  for(i=0 ; i<linhas ; i++){
    for(j=0 ; j<colunas ; j++){
      if(M[i][j]=='B'){
	scanf("%c",&movimento);
	if(movimento=='c'){
	  if(M[i-1][j]!='S'||M[i-1][j]!='D'||M[i-1][j]!='C'||M[i-1][j]!='P'||M[i-1][j]!='H'){
	    M[i-1][j]='B';
	    M[i][j]='T';
	    moveu=1;
	  }
	}
	if(movimento=='b'){
	  if(M[i+1][j]!='S'||M[i+1][j]!='D'||M[i+1][j]!='C'||M[i+1][j]!='P'||M[i+1][j]!='H'){
	    M[i+1][j]='B';
	    M[i][j]='T';
	    moveu=1;
	  }
	}
	if(movimento=='e'){
	  if(M[i][j-1]!='S'||M[i][j-1]!='D'||M[i][j-1]!='C'||M[i][j-1]!='P'||M[i][j-1]!='H'){
	    M[i][j-1]='B';
	    M[i][j]='T';
	    moveu=1;
	  }
	}
	if(movimento=='d'){
	  if(M[i][j+1]!='S'||M[i][j+1]!='D'||M[i][j+1]!='C'||M[i][j+1]!='P'||M[i][j+1]!='H'){
	    M[i][j+1]='B';
	    M[i][j]='T';
	    moveu=1;
	  }
	}
      }
    }
  }
  return moveu;
}
