#include <stdio.h>
#include "libmatriz.h"
#include "libmapa.h"

int main() {
    Mapa *mapa;

    mapa = leia_mapa_prompt();
    escreva_mapa_tela(mapa);
    printf("%d %d\n", linhas(mapa), colunas(mapa));
    escreva_matriz_tela(matriz(mapa), linhas(mapa), colunas(mapa));
    libera_mapa(mapa);
    return 0;
}
