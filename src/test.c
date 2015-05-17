#include <stdio.h>
#include "matriz.h"

int main() {
    char **M;

    leia_mapa(M);
    escreva_mapa_tela(M);
    LiberaMatriz(M);
    return 0;
}
