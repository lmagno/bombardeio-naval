#include <stdio.h>
#include "libmatriz.h"
#include "libmapa.h"

int main() {
    Mapa *mapa;
    char **M;
    int m, i;

    mapa = leia_mapa_prompt();
    escreva_mapa_tela(mapa);
    printf("%d %d\n", linhas(mapa), colunas(mapa));
    escreva_matriz_tela(matriz(mapa), linhas(mapa), colunas(mapa));
    M = matriz(mapa);
    printf("começo!\n");
    for (i = 0; i < linhas(mapa); i++) printf("%s\n", M[i]);
    libera_mapa(mapa);
    return 0;
}
