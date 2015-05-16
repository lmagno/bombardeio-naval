#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** AlocaMatriz(int m,int n){
    int** M;
    int i;
    M=(int **)malloc(m*sizeof(int *));
    for(i=0 ; i<m;i++){
        M[i]=(int*)malloc(n*sizeof(int));
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

char ** ler_matriz(char** M){
  FILE *mapa;
  Char nome[50];
  int linhas,colunas,i,j;
  printf("digite o nome do arquivo mapa: ");
  scanf("%s",nome);
  mapa=fopen(nome,"r");
  if(mapa!=NULL){
    fscanf(mapa,"%s",linhas);
    fscanf(mapa,"%s",colunas);
    M=AlocaMatriz(linhas,colunas);
    for(i=0 ; i<linhas ; i++){
      for(j=0 ; j<colunas ; j++){
	fscanf(mapa,"%c",&M[i][j]);
      }
    }
    fcolse(mapa);
  }
  else{
    printf("arquivo não enontrado: digite o numero de linhas e colunas respectivamente para novo mapa");
    scanf("%s",linhas);
    scanf("%s",colunas);
    M=AlocaMatriz(linhas,colunas);
    for(i=0 ; i<linhas ; i++){
      for(j=0 ; j<colunas ; j++){
	M[i][j]='.';
      }
    }
  }
  return M; 
}

void imprime_tela(char **M,int linhas,int colunas){
  int i,j;
  for(i=0 ; i<linhas ; i++){
    for(j=0 ; j<colunas ; j++){
      if(M[i][j]=='*'||M[i][j]='!'||M[i][j]='='||M[i][j]='+'||M[i][j]='B'||M[i][j]='T')
	printf("%c",M[i][j]);
      else
	printf("-");
    }
  }
}

void escrever_mapa(char **M,int linhas,int colunas){
  
	




int main(){
  
return 0;
}
