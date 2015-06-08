#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libstatus.h"

void testa_trata_status_sucesso(CuTest *tc);
void testa_trata_status_erro(CuTest *tc);
void testa_trata_status_erro_alocacao(CuTest *tc);

CuSuite* test_status_get_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testa_trata_status_sucesso);
    SUITE_ADD_TEST(suite, testa_trata_status_erro);
    SUITE_ADD_TEST(suite, testa_trata_status_erro_alocacao);

    return suite;
}

Status* retorna_sucesso() {
    return sucesso();
}

Status* retorna_erro() {
    return erro(1, "Erro :c");
}

Status* retorna_erro_alocacao() {
    char *message;
    message = malloc(50*sizeof(char));
    sprintf(message, "Erro :c");
    return erro(2, message);
}

void testa_trata_status_sucesso(CuTest *tc) {
    Status *sts;
    int id;

    sts = retorna_sucesso();
    id = trata_status(sts);
    CuAssertIntEquals(tc, 0, id);
}

void testa_trata_status_erro(CuTest *tc) {
    Status *sts;
    int id;

    sts = retorna_erro();
    id = trata_status(sts);
    CuAssertIntEquals(tc, 1, id);
}

void testa_trata_status_erro_alocacao(CuTest *tc) {
    Status *sts;
    int id;

    sts = retorna_erro_alocacao();
    id = trata_status(sts);
    CuAssertIntEquals(tc, 2, id);
}
