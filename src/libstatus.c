#include <stdio.h>
#include <stdlib.h>
#include "libstatus.h"

// Struct representando o valor de retorno de uma função.
// Toda função de maior nível (que não seja do próprio C)
// deve retornar esta struct, indicando o valor de retorno
// (0 para sucesso, outros valores para erro.
// "Status_Tag" é somente um marcador e não deve ser utilizado,
// use "Status" ao invés.
struct Status_Tag {
    int valor;
    char *mensagem;
};

typedef struct Status_Tag Status;

// Função que retorna um Status com valor 0,
// indicando sucesso, e sem mensagem atribuída.
// Exemplo:
//     ...
//     return sucesso();
Status* sucesso() {
    Status *sts;

    sts = malloc(sizeof(Status));
    sts->valor = 0;

    return sts;
}

// Função que retorna um Status com valor e mensagem
// atribuidos, indicando um erro. Por este motivo,
// o valor passado a ela deve ser diferente de 0,
// pois existe a função "sucesso" para tratar este caso.
// Caso o valor passado a ela seja 0, ela imprime um warning.
// Recebe:
//     int valor: valor representando o tipo de erro
//             (deve ser diferente de 0).
//     char *mensagem: string contendo a mensagem de erro associada.
// Retorna:
//     Status *sts: ponteiro para um Status indicando o estado da
//                  execução
Status* erro(int valor, char *mensagem) {
    Status *sts;

    if (valor == 0) fprintf(stderr, "WARNING: erro com status 0.\n");

    sts = malloc(sizeof(Status));
    sts->valor      = valor;
    sts->mensagem = mensagem;

    return sts;
}

// Libera um Status previamente alocado.
void libera_status(Status *sts) {
    free(sts->mensagem);
    free(sts);
}

// Trata o Status retornado por alguma função, isto é,
// imprime a mensagem de erro caso valor != 0 (erro).
// Em qualquer caso, porém, libera o Status recebido
// e retorna o valor deste, para poder ser usado 
// posteriormente (em loops, por exemplo).
// Recebe:
//     Status *sts: Status a ser tratado
// Retorna:
//     int valor: valor do status recebido
int trata_status(Status *sts) {
    int        valor = sts->valor;
    char *mensagem = sts->mensagem;

    if (valor != 0) {
        fprintf(stderr, "%s\n", mensagem);
    }

    libera_status(sts);
    return valor;
}
