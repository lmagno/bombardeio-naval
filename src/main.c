#include <stdio.h>
#include "libutils.h"
#include "libmapa.h"
#include "libembarcacoes.h"

#define FALSE 0
#define TRUE 1

int main() {
    Mapa *mapa;
    char **M;
    int x_barco, y_barco;
    int fim_de_jogo = FALSE;

    mapa = leia_mapa_prompt();
    /* Mas precisamos da string com o nome do arquivo pra poder chamar dispara_tiros*/

    /*posiciona_barco();*/

    escreva_mapa_tela(mapa);

    while(!fim_de_jogo){
        rema_barco(mapa,x_barco,y_barco);        
        fim_de_jogo = dispara_tiros(mapa, arquivo);
    }

    libera_mapa(mapa);
    return 0;
}
