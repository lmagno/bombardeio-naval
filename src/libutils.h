#ifndef libutils_h__
#define libutils_h__

extern char ** aloca_matriz(int m, int n);
extern void libera_matriz(char **M, int m);
extern void escreva_matriz_tela(char **M, int m, int n);
extern void descarta_resto_linha(FILE *arq);
extern char prox_elem(FILE *arq);
extern Status* anexa_arquivo(char *nome, char *str);
Status* read_char(char *c);
Status* read_int(int *d);
Status* read_str(char *s);

#endif
