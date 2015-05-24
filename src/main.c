#include <stdio.h>
#include "libutils.h"
#include "libmapa.h"
#include "libembarcacoes.h"
#include "libbarco.h"

#define FALSE 0
#define TRUE 1

int main() {
    Mapa *mapa;
    char **M;
    char arquivo[32];
    int x_barco, y_barco;
    int fim_de_jogo = FALSE;
    int err = FALSE;

    printf("Entre com o nome do arquivo que contém o mapa: ");
    read_str(arquivo);

    err = leia_mapa_arquivo(&mapa, arquivo);

    while(err){
        printf("Arquivo inválido. Insira o nome de um arquivo válido: ");
        read_str(arquivo);
    }

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
