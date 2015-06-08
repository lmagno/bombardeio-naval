#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libutils.h"

// Aloca uma matriz char mxn
// e retorna seu ponteiro
char** aloca_matriz(int m,int n){
    char **M;
    int i;
    M=(char **)malloc(m*sizeof(char *));
    for(i=0 ; i<m;i++){
        M[i]=(char*)malloc(n*sizeof(char));
    }
    return M;
}

// Recebe o ponteiro para uma matriz char M
// e libera toda a memória alocada a ela
void libera_matriz(char **M, int m){
    int i;

    for(i = 0 ; i < m ; i++){
        free(M[i]);
    }
    free(M);
}

// Recebe o ponteiro para uma matriz char mxn
// e imprime todo seu conteúdo para a STDOUT
void escreva_matriz_tela(char **M, int m, int n){
    int i, j;

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%c", M[i][j]);
        }
        printf("\n");
    }
}

// Recebe o ponteiro para um arquivo e avança seu buffer até uma
// quebra de linha.
void descarta_resto_linha(FILE *arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c != '\n');
}

// Recebe o ponteiro para um arquivo e avança seu buffer até o primeiro
// caracter que não seja whitespace, retornando ele em seguida.
char prox_elem(FILE *arq) {
    char c;
    do fscanf(arq, "%c", &c);
    while (c == ' ' || c == '\t');

    return c;
}

// Recebe o nome de um arquivo e uma string e a concatena
// ao final desse arquivo.
// Retorna:
//     0: em caso de sucesso
//     1: caso não consiga abrir o arquivo (erro)
Status* anexa_arquivo(char *nome, char *str) {
    FILE *arq;
    char *msg;

    arq = fopen(nome, "a");
    if (arq == NULL) {
        msg = malloc(258*sizeof(char));
        sprintf(msg, "Não foi possível abrir o arquivo '%s'.", nome);
        return erro(1, msg);
    }

    fprintf(arq, "%s", str);
    fclose(arq);
    return sucesso();
}

// Lê um caracter da entrada padrão
// Recebe:
//     char *c: ponteiro para o caracter onde será gravado o caracter
//              lido da entrada
// Retorna:
//      0: em caso de sucesso
//     -1: caso não tenha sido possível ler da stdin
//      1: caso o número errado de caracteres tenha sido fornecido (0 ou mais
//         de 1)
Status* read_char(char *c) {
    char *line, c1, c2;
    size_t len;
    ssize_t read;

    len = 256;
    line = malloc(len*sizeof(char));

    if (getline(&line, &len, stdin) != -1){
        read = sscanf(line, " %c %c", &c1, &c2);
        switch(read) {
            case 1:
                *c = c1;
                free(line);
                return sucesso();
            default:
                free(line);
                return erro(1, "Número errado de caracteres fornecidos.");
        }
    }
    else {
        free(line);
        return erro(-1, "Não foi possível ler da stdin.");
    }
}

// Lê um inteiro da entrada padrão
// Recebe:
//     int *c: ponteiro para o caracter onde será gravado o caracter
//              lido da entrada
// Retorna:
//      0: em caso de sucesso
//     -1: caso não tenha sido possível ler da stdin
//      1: caso o número errado de números tenha sido fornecido (0 ou mais
//         de 1)
Status* read_int(int *d) {
    char *line;
    int d1, d2;
    size_t len;
    ssize_t read;

    len = 256;
    line = malloc(len*sizeof(char));

    if (getline(&line, &len, stdin) != -1){
        read = sscanf(line, " %d %d", &d1, &d2);
        switch(read) {
            case 1:
                *d = d1;
                free(line);
                return sucesso();
            default:
                free(line);
                return erro(1, "Número errado de números fornecidos.");
        }
    }
    else {
        free(line);
        return erro(-1, "Não foi possível ler da stdin.");
    }
}

// Lê uma string da entrada padrão
// Recebe:
//     int *s: string onde será gravado o caracter lido da entrada
// Retorna:
//      0: em caso de sucesso
//     -1: caso não tenha sido possível ler da stdin
//      1: caso o número errado de strings tenha sido fornecido (0 ou mais
//         de 1)
Status* read_str(char *s) {
    char *line;
    char s1[256], c2;
    size_t len;
    ssize_t read;

    len = 256;
    line = malloc(len*sizeof(char));

    if (getline(&line, &len, stdin) != -1){
        read = sscanf(line, " %s %c", s1, &c2);
        switch(read) {
            case 1:
                strcpy(s, s1);
                free(line);
                return sucesso();
            default:
                free(line);
                return erro(1, "Número errado de strings fornecidas.");
        }
    }
    else {
        free(line);
        return erro(-1, "Não foi possível ler da stdin.");
    }
}
