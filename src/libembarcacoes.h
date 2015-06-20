

#undef Status    
#include "libbarco.h"            // Por quê?

#ifndef libembarcacoes_h__
#define libembarcacoes_h__

void afunda_destroyer(Mapa *mapa, int x, int y, int d,WINDOW *w,PIC explosion);
void afunda_cruzador(Mapa *mapa, int x, int y, int d,WINDOW *w,PIC explosion);
void afunda_porta_aviao(Mapa *mapa, int x, int y, int d,WINDOW *w,PIC explosion);
void afunda_hidro_aviao(Mapa *mapa,int x,int y, int d,WINDOW *w,PIC explosion);
int sorteia(int k);
void coordenadas_tiro(Mapa *mapa, int *x_tiro, int *y_tiro);
char identifica_alvo_atingido(Mapa *mapa, int x_tiro, int y_tiro, char* arquivo);
void dispara_tiros(Mapa *mapa, char *arquivo, int *acertou_barco,WINDOW *w,PIC explosion);

#endif
