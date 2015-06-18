#include <stdio.h>
#include "libembarcacoes.h"

// libs do xwc:
#include "libxwc.h"
#include <unistd.h>

#undef Status                // Por quê?
#include <mcheck.h>          // valgrind

#define FALSE     0
#define TRUE      1
#define SPR_SIZE 32    // O tamanho de cada sprite;

void abre_mapa(Mapa **mapa);
void seleciona_arquivo_saida(char *saida);

int main(int ac, char **av) {
    // Isso tem a ver com o valgrind?
    mtrace();

    // Variáveis da engine do jogo:
    Mapa *mapa;
    char saida[50];
    int x_barco, y_barco;
    int beco_3x,             // "Booleanas" de passagem 
        acertou_barco;
    char acao = 'q';         
    Status *sts;

    // Variáveis relacionadas ao xwc:
    WINDOW *w;
    //PIC barco, Aux;
    //MASK msk;
    int window_w, window_h;

    printf("        B O M B A R D E I O   N A V A L        \n\n\n");
    
    do {
	    printf("Digite s para sair ou digite j para jogar: ");
        sts = read_char(&acao);
        
    } while (trata_status(sts));
    
    if (acao == 'j') {

        abre_mapa(&mapa);
        seleciona_arquivo_saida(saida);

        // Define as dimensões da janela (baseadas no tamanho do mapa):
        w_width = colunas(mapa) * SPR_SIZE;
        w_height = linhas(mapa) * SPR_SIZE;

        // xwc - abre a janela principal
        w = InitGraph(w_width, w_height, "Bombardeio Naval");


    	posiciona_barco(mapa, &x_barco, &y_barco);

    	escreva_mapa_tela(mapa);
    	escreva_mapa_arquivo(saida, mapa);

    	beco_3x       = FALSE;
    	acertou_barco = FALSE;
        
    	while(TRUE) {
            // A próxima remada:
            rema_barco(mapa, &x_barco, &y_barco, &beco_3x);
            
            if (beco_3x) {
                printf("Você perdeu o jogo. D:\n");
                break;
            }

            // Os tiros:
            dispara_tiros(mapa, saida, &acertou_barco);

            // O barco foi acertado?
            if (acertou_barco) {
                printf("Você perdeu o jogo. D:\n");
                break;
            }
           
            // O jogador chegou ao final do tabuleiro?
            if (y_barco == linhas(mapa) - 1) {
                printf("\nParabéns! Você ganhou! :D\n");
                break;
            }
        }

        libera_mapa(mapa);

        // xwc - Fecha a janela principal
        CloseGraph();
    }

    // valgrind 
    muntrace();
    
    return 0;
}

void abre_mapa(Mapa **mapa) {
    Status *sts;
    char entrada[50];

    do {
        do {
            printf("Entre com o nome do arquivo que contém o mapa: ");
            sts = read_str(entrada);
        } while (trata_status(sts));

        sts = leia_mapa_arquivo(mapa, entrada);
    } while (trata_status(sts));
}

void seleciona_arquivo_saida(char *saida) {
    Status *sts;

    do {
        printf("Entre com o nome do arquivo de saída: ");
        sts = read_str(saida);
    } while (trata_status(sts));
}
