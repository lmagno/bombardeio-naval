#include "libutils.h"

#ifndef libmapa_h__
#define libmapa_h__

typedef struct MapaTag Mapa;
extern Status* leia_mapa_arquivo(Mapa **mapa, char *nome);
extern void escreva_mapa_tela(Mapa *mapa);
extern Status* escreva_mapa_arquivo(char *nome, Mapa *mapa);
extern void libera_mapa(Mapa *mapa);
extern char** matriz(Mapa *mapa);
extern int linhas(Mapa *mapa);
extern int colunas(Mapa *mapa);

#endif
