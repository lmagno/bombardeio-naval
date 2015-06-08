#include <stdio.h>
#include "libembarcacoes.h"

#define FALSE 0
#define TRUE 1

int main() {
    Mapa *mapa;
    char arquivo[32];
    int x_barco, y_barco;
    int fim_de_jogo = FALSE;
    Status *sts;

    do {
        do {
            printf("Entre com o nome do arquivo que contém o mapa: ");
            sts = read_str(arquivo);
        } while(trata_status(sts));

        sts = leia_mapa_arquivo(&mapa, arquivo);
    } while(trata_status(sts));

    posiciona_barco(mapa, &x_barco, &y_barco);

    escreva_mapa_tela(mapa);
    escreva_mapa_arquivo(arquivo,mapa);

    while(!fim_de_jogo){
        rema_barco(mapa,&x_barco,&y_barco);
        fim_de_jogo = dispara_tiros(mapa, arquivo);
    }

    libera_mapa(mapa);

    return 0;
}
