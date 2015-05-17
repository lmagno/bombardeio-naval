#ifndef libmapa_h__
#define libmapa_h__

typedef struct MapaTag Mapa;
extern Mapa* leia_mapa();
extern void escreva_mapa_tela(Mapa *mapa);
extern int escreva_mapa_arquivo(Mapa *mapa);
extern void libera_mapa(Mapa *mapa);
extern char** matriz(Mapa *mapa);
extern int linhas(Mapa *mapa);
extern int colunas(Mapa *mapa);

#endif
