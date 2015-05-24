#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libutils.h"
#include "libmapa.h"
#include "libbarco.h"

#define FALSE 0
#define TRUE  1

void posiciona_barco(Mapa *mapa, int *x, int *y){
    char posicionou = FALSE;
    int i, j, posicao, err;
    char ** M = matriz(mapa);

    printf("Posições disponíveis: ");
    for (j = 0; j < colunas(mapa); j++)
        if (M[0][j] == '.')
            printf("%d ", j);

    printf("\n");
    while(!posicionou){
        printf("Digite a posição inicial do barco: \n");
        while(err = read_int(&posicao)) {
            printf("err = %d\n", err);
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
    char ** M = matriz(mapa);
    char movimento;
    int i, j,
        dx, dy,
        moveu, escolheu;


    printf("Entre com um movimento para o barco: ");
    read_char(&movimento);

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
                    read_char(&movimento);
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
            read_char(&movimento);
        }
    }

    *x_B = j;
    *y_B = i;
}
