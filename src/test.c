#include <stdio.h>
#include "libmatriz.h"

int main() {
    char **M;
    int m, n;

    leia_mapa(M, &m, &n);
    escreva_mapa_tela(M, m, n);
    LiberaMatriz(M, m);
    return 0;
}