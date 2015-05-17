#ifndef libmatriz_h__
#define libmatriz_h__

extern char ** aloca_matriz(int m, int n);
extern void libera_matriz(char **M, int m);
extern int leia_matriz(char *nome, char** M, int *m, int *n);
extern void escreva_matriz_tela(char **M, int m, int n);

#endif
