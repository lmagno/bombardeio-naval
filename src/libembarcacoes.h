#ifndef libembarcacoes_h__
#define libembarcacoes_h__

void afunda_destroyer(Mapa *mapa, int x, int y);
void afunda_cruzador(Mapa *mapa, int x, int y);
void afunda_porta_aviao(Mapa *mapa, int x, int y);
void afunda_hidro_aviao(Mapa *mapa,int x,int y);
void posiciona_barco(Mapa *mapa);
int sorteia(int k);
void coordenadas_tiro(Mapa *mapa, int *x_tiro, int *y_tiro);
char identifica_alvo_atingido(Mapa *mapa, int x_tiro, int y_tiro);
int dispara_tiros(Mapa *mapa);

#endif