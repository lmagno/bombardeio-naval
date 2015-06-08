#include "libbarco.h"

#ifndef libembarcacoes_h__
#define libembarcacoes_h__

void afunda_destroyer(Mapa *mapa, int x, int y, int d);
void afunda_cruzador(Mapa *mapa, int x, int y, int d);
void afunda_porta_aviao(Mapa *mapa, int x, int y, int d);
void afunda_hidro_aviao(Mapa *mapa,int x,int y, int d);
int sorteia(int k);
void coordenadas_tiro(Mapa *mapa, int *x_tiro, int *y_tiro);
char identifica_alvo_atingido(Mapa *mapa, int x_tiro, int y_tiro, char* arquivo);
int dispara_tiros(Mapa *mapa, char *arquivo);

#endif
