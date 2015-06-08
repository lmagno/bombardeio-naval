#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstatus.h"
#include "libutils.h"
#include "libmapa.h"
#include "libbarco.h"

#define FALSE 0
#define TRUE  1

void posiciona_barco(Mapa *mapa, int *x, int *y){
    char posicionou = FALSE;
    int i, j, posicao, err;
    char ** M = matriz(mapa);
    Status *sts;

    printf("Posições disponíveis: ");
    for (j = 0; j < colunas(mapa); j++)
        if (M[0][j] == '.')
            printf("%d ", j);

    printf("\n");
    while(!posicionou){
        printf("Digite a posição inicial do barco: ");
        sts = read_int(&posicao);
        while(trata_status(sts)) {
            sts = read_int(&posicao);
        }

        if(M[0][posicao] == '.'){
            M[0][posicao] = 'B';
            *x = posicao;
            *y = 0;
            posicionou = TRUE;
        }
        else
            printf("Posição não disponível.");
    }
}

void rema_barco(Mapa *mapa, int *x_B, int *y_B){
    Status *sts;
    char ** M = matriz(mapa);
    char movimento;
    int i, j,
        dx, dy,
        moveu, escolheu;


    printf("Entre com um movimento para o barco: ");
    do
        sts = read_char(&movimento);
    while(trata_status(sts));

    moveu = FALSE;
    while(!moveu){

        escolheu = FALSE;
        while(!escolheu){
            switch(movimento) {
                case 'c':
                    dx =  0;
                    dy = -1;
                    escolheu = TRUE;
                    break;

                case 'b':
                    dx = 0;
                    dy = 1;
                    escolheu = TRUE;
                    break;

                case 'e':
                    dx = -1;
                    dy =  0;
                    escolheu = TRUE;
                    break;

                case 'd':
                    dx = 1;
                    dy = 0;
                    escolheu = TRUE;
                    break;

                default:
                    printf("Movimento não reconhecido.\n");
                    printf("Entre com um dos seguintes: (c)ima, (b)aixo, (e)squerda, (d)ireita: ");
                    do
                        sts = read_char(&movimento);
                    while(trata_status(sts));
                    break;
            }
        }

        j = *x_B + dx;
        i = *y_B + dy;

        printf("%d %d\n", i, j);
        if(i >= 0 && i <  linhas(mapa) &&
           j >= 0 && j < colunas(mapa) &&
           M[i][j] != 'D' && M[i][j] != 'C' &&
           M[i][j] != 'P' && M[i][j] != 'H') {

            M[i][j] = 'B';
            M[*y_B][*x_B] = 'T';
            moveu = TRUE;
        } else {
            printf("Esse movimento não é possível!\n");
            printf("Entre com outro movimento para o barco: \n");
            do
                sts = read_char(&movimento);
            while(trata_status(sts));
        }
    }

    *x_B = j;
    *y_B = i;
}
