#include <stdio.h>
#include "libembarcacoes.h"

#define FALSE 0
#define TRUE 1

void abre_mapa(Mapa **mapa);
void seleciona_arquivo_saida(char *saida);

int main() {
    Mapa *mapa;
    char saida[50];
    int x_barco, y_barco;
    int beco_3x,
        acertou_barco;
    char acao = 'q';
    Status *sts;
    printf("        B O M B A R D E I R O   N A V A L        \n\n\n");
    while(1){
	do {
	    printf("digite s para sair ou digite j para jogar:");
            sts = read_char(&acao);
	}while(trata_status(sts)&&(acao!='j'||acao!='q'));
        if(acao == 'j'){

    	    abre_mapa(&mapa);
    	    seleciona_arquivo_saida(saida);
    	    posiciona_barco(mapa, &x_barco, &y_barco);

    	    escreva_mapa_tela(mapa);
    	    escreva_mapa_arquivo(saida, mapa);

    	    beco_3x = FALSE;
    	    acertou_barco = FALSE;
    	    while(1){
                rema_barco(mapa, &x_barco, &y_barco, &beco_3x);
                if (beco_3x) {
                    printf("Você perdeu o jogo. D:\n");
                    break;
                }

                dispara_tiros(mapa, saida, &acertou_barco);
                if(acertou_barco) {
                    printf("Você perdeu o jogo. D:\n");
                    break;
                }
        
                if (y_barco == linhas(mapa) - 1) {
                    printf("\nParabéns! Você ganhou! :D\n");
                    break;
                }
            }

            libera_mapa(mapa);
        }
        else if(acao == 'q')
    	    break;
    }
    
    return 0;
}

void abre_mapa(Mapa **mapa) {
    Status *sts;
    char entrada[50];

    do {
        do {
            printf("Entre com o nome do arquivo que contém o mapa: ");
            sts = read_str(entrada);
        } while(trata_status(sts));

        sts = leia_mapa_arquivo(mapa, entrada);
    } while(trata_status(sts));
}

void seleciona_arquivo_saida(char *saida) {
    Status *sts;

    do {
        printf("Entre com o nome do arquivo de saída: ");
        sts = read_str(saida);
    } while(trata_status(sts));
}
