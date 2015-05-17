#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** AlocaMatriz(int m,int n){
    char** M;
    int i;
    M=(char **)malloc(m*sizeof(char *));
    for(i=0 ; i<m;i++){
        M[i]=(char*)malloc(n*sizeof(char));
    }
return M;
}

void LiberaMatriz(char **M,int n){
int i;
for(i=0 ; i<n ; i++){
    free(M[i]);
}
 free(M);
}

char ** leia_mapa(char** M, int *m, int *n){
  FILE *mapa;
  char nome[50];
  int linhas,colunas,i,j;
  printf("digite o nome do arquivo mapa: ");
  scanf("%s",nome);
  mapa=fopen(nome,"r");
  if(mapa!=NULL){
    fscanf(mapa,"%d",&linhas);
    fscanf(mapa,"%d",&colunas);
    M=AlocaMatriz(linhas,colunas);
    for(i=0 ; i<linhas ; i++){
      for(j=0 ; j<colunas ; j++){
	fscanf(mapa,"%c",&M[i][j]);
      }
    }
    fclose(mapa);
  }
  else{
    printf("arquivo não enontrado: digite o numero de linhas e colunas respectivamente para novo mapa");
    scanf("%d",&linhas);
    scanf("%d",&colunas);
    M=AlocaMatriz(linhas,colunas);
    for(i=0 ; i<linhas ; i++){
      for(j=0 ; j<colunas ; j++){
	M[i][j]='.';
      }
    }
  }
  *m = linhas;
  *n = colunas;
  return M;
}

void escreva_mapa_tela(char **M,int linhas,int colunas){
  int i,j;
  for(i=0 ; i<linhas ; i++){
    for(j=0 ; j<colunas ; j++){
      if(M[i][j]=='*'||M[i][j]=='!'||M[i][j]=='='||M[i][j]=='+'||M[i][j]=='B'||M[i][j]=='T')
	printf("%c",M[i][j]);
      else
	printf("-");
    }
  }
}

void escrever_mapa_arquivo(char **M,int linhas,int colunas){
  char nome[50];
  FILE *mapa;
  int i,j;
  printf("digite o nome do mapa a ser salvo: \n");
  scanf("%s",nome);
  mapa=fopen(nome,"w");
  fprintf(mapa,"%d %d\n\n",linhas,colunas);
  for(i=0 ; i<linhas ; i++){
    for(j=0 ; j<colunas ; j++){
      fprintf(mapa,"%d ",M[i][j]);
    }
  }
  fclose(mapa);
}
