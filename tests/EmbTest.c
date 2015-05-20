#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libmapa.h"
#include "../src/libutils.h"
#include "../src/libembarcacoes.h"

void test_afunda_destroyer1(CuTest *tc);
void test_afunda_destroyer2(CuTest *tc);
void test_sorteia(CuTest *tc);
char** str_vec(Mapa *mapa);
Mapa* get_mapa(CuTest *tc, int i);

CuSuite* test_emb_get_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_sorteia);
    SUITE_ADD_TEST(suite, test_afunda_destroyer1);
    SUITE_ADD_TEST(suite, test_afunda_destroyer2);
    return suite;
}

void test_afunda_destroyer2(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 1);
    CuAssert(tc, "Não tem nenhum destroyer pra afundar nesta casa!", matriz(mapa)[2][4] == 'D');
    afunda_destroyer(mapa, 4, 2, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "DD.**...", N[2]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_destroyer1(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 1);
    CuAssert(tc, "Não tem nenhum destroyer pra afundar nesta casa!", matriz(mapa)[2][0] == 'D');
    afunda_destroyer(mapa, 0, 2, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "**.DD...", N[2]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_sorteia(CuTest *tc) {
    int i, r;

    for (i = 1; i < 10000; i++) {
        r = sorteia(i);
        CuAssertTrue(tc, r < i);
    }
}

Mapa* get_mapa(CuTest *tc, int i) {
    Mapa *mapa;
    int err;
    char nome[50];

    sprintf(nome, "./tests/mapa%1d.dat", i);
    err = leia_mapa_arquivo(&mapa, nome);
    CuAssertIntEquals(tc, 0, err);
    return mapa;
}
