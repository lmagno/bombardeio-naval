#ifndef libmatriz_h__
#define libmatriz_h__

extern char ** aloca_matriz(int m,int n);
extern void libera_matriz(char **M,int n);
extern char ** leia_mapa(char** M, int *m, int *n);
extern void escreva_mapa_tela(char **M,int linhas,int colunas);
extern void escrever_mapa_arquivo(char **M,int linhas,int colunas);

#endif
