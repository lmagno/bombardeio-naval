#ifndef libmapa_h__
#define libmapa_h__

extern Mapa;
extern Mapa* leia_mapa();
extern void escreva_mapa_tela(Mapa *mapa);
extern int escrever_mapa_arquivo(Mapa *mapa);

#endif
