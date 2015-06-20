#include <stdio.h>

// libs do xwc:
#include "libxwc.h"
#include <unistd.h>

#undef Status                // Por quê?
#include "libembarcacoes.h"
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
    PIC barco_h,barco_v, Aux,explosion;
    
    MASK msk_b;
    int window_w, window_h;
    int w_width,w_height;
    int x_anterior,y_anterior;
    int cor_do_caminho = 2000;

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
        barco_v = ReadPic(w,"barco1.xpm",NULL);
        barco_h = ReadPic(w,"barco2.xpm",NULL);
        explosion = ReadPic(w,"explosion.xpm",NULL);
        msk_b = NewMask(explosion,16,16);
        Aux = ReadPic(w, "explosion.xpm", msk_b);
    	posiciona_barco(mapa, &x_barco, &y_barco);
        PutPic(w, barco_v,0, 0, SPR_SIZE, SPR_SIZE, x_barco*SPR_SIZE, y_barco*SPR_SIZE);
    	escreva_mapa_tela(mapa);
    	escreva_mapa_arquivo(saida, mapa);

    	beco_3x       = FALSE;
    	acertou_barco = FALSE;
        
    	while(TRUE) {
            // A próxima remada:
            x_anterior=x_barco;
            y_anterior=y_barco;
            rema_barco(mapa, &x_barco, &y_barco, &beco_3x);
            if(x_anterior!=x_barco)
                PutPic(w, barco_h,0, 0, SPR_SIZE, SPR_SIZE, x_barco*SPR_SIZE, y_barco*SPR_SIZE);
            if(y_anterior!=y_barco)
                PutPic(w, barco_v,0, 0, SPR_SIZE, SPR_SIZE, x_barco*SPR_SIZE, y_barco*SPR_SIZE);
            WFillRect(w, x_anterior*SPR_SIZE, y_anterior*SPR_SIZE, SPR_SIZE, SPR_SIZE, cor_do_caminho);
            //pinta quadrado anterior com caminho
            if (beco_3x) {
                printf("Você perdeu o jogo. D:\n");
                break;
            }

            // Os tiros:
            dispara_tiros(mapa, saida, &acertou_barco, w, explosion);

            // O barco foi acertado?
            if (acertou_barco) {
                SetMask(w,msk_b);
                PutPic(w, Aux, 0,0, SPR_SIZE, SPR_SIZE, x_barco, y_barco);
                printf("Você perdeu o jogo. D:\n");
                break;
            }
           
            // O jogador chegou ao final do tabuleiro?
            if (y_barco == linhas(mapa) - 1) {
                printf("\nParabéns! Você ganhou! :D\n");
	        //PUT PIC
                break;
            }
            //limpar explosãoes
            
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
