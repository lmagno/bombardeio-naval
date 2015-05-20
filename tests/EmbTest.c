#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libmapa.h"
#include "../src/libutils.h"
#include "../src/libembarcacoes.h"

void test_afunda_destroyer1(CuTest *tc);
void test_afunda_destroyer2(CuTest *tc);
void test_afunda_destroyer3(CuTest *tc);
void test_afunda_destroyer4(CuTest *tc);
void test_afunda_cruzador1(CuTest *tc);
void test_afunda_cruzador2(CuTest *tc);
void test_afunda_cruzador3(CuTest *tc);
void test_afunda_cruzador4(CuTest *tc);
void test_afunda_porta_aviao1(CuTest *tc);
void test_afunda_porta_aviao2(CuTest *tc);
void test_afunda_porta_aviao3(CuTest *tc);
void test_afunda_porta_aviao4(CuTest *tc);
void test_afunda_hidro_aviao1(CuTest *tc);
void test_afunda_hidro_aviao2(CuTest *tc);
void test_sorteia(CuTest *tc);
char** str_vec(Mapa *mapa);
Mapa* get_mapa(CuTest *tc, int i);

CuSuite* test_emb_get_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_sorteia);
    SUITE_ADD_TEST(suite, test_afunda_destroyer1);
    SUITE_ADD_TEST(suite, test_afunda_destroyer2);
    SUITE_ADD_TEST(suite, test_afunda_destroyer3);
    SUITE_ADD_TEST(suite, test_afunda_destroyer4);
    SUITE_ADD_TEST(suite, test_afunda_cruzador1);
    SUITE_ADD_TEST(suite, test_afunda_cruzador2);
    SUITE_ADD_TEST(suite, test_afunda_cruzador3);
    SUITE_ADD_TEST(suite, test_afunda_cruzador4);
    SUITE_ADD_TEST(suite, test_afunda_porta_aviao1);
    SUITE_ADD_TEST(suite, test_afunda_porta_aviao2);
    SUITE_ADD_TEST(suite, test_afunda_porta_aviao3);
    SUITE_ADD_TEST(suite, test_afunda_porta_aviao4);
    SUITE_ADD_TEST(suite, test_afunda_hidro_aviao1);
    SUITE_ADD_TEST(suite, test_afunda_hidro_aviao2);
    return suite;
}

void test_afunda_hidro_aviao2(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum hidro-avião pra afundar nesta casa!", matriz(mapa)[1][13] == 'H');
    afunda_destroyer(mapa, 13, 1, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "..........H..*...P", N[1]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_hidro_aviao1(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum hidro-avião pra afundar nesta casa!", matriz(mapa)[4][0] == 'H');
    afunda_destroyer(mapa, 0, 4, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "*..P..C...D..D.S.P", N[4]);


    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_porta_aviao4(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum porta-avião pra afundar nesta casa!", matriz(mapa)[5][17] == 'P');
    afunda_destroyer(mapa, 17, 5, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "..........H..H...*", N[1]);
    CuAssertStrEquals(tc, ".P.....DD.....H..*", N[2]);
    CuAssertStrEquals(tc, "..P..C......D....*", N[3]);
    CuAssertStrEquals(tc, "H..P..C...D..D.S.*", N[4]);
    CuAssertStrEquals(tc, ".H..P..C..D......*", N[5]);


    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_porta_aviao3(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum porta-avião pra afundar nesta casa!", matriz(mapa)[1][17] == 'P');
    afunda_destroyer(mapa, 17, 1, 0);

    N = str_vec(mapa);


    CuAssertStrEquals(tc, "..........H..H...*", N[1]);
    CuAssertStrEquals(tc, ".P.....DD.....H..*", N[2]);
    CuAssertStrEquals(tc, "..P..C......D....*", N[3]);
    CuAssertStrEquals(tc, "H..P..C...D..D.S.*", N[4]);
    CuAssertStrEquals(tc, ".H..P..C..D......*", N[5]);


    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_porta_aviao2(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum porta-avião pra afundar nesta casa!", matriz(mapa)[6][5] == 'P');
    afunda_destroyer(mapa, 5, 6, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, ".*.....DD.....H..P", N[2]);
    CuAssertStrEquals(tc, "..*..C......D....P", N[3]);
    CuAssertStrEquals(tc, "H..*..C...D..D.S.P", N[4]);
    CuAssertStrEquals(tc, ".H..*..C..D......P", N[5]);
    CuAssertStrEquals(tc, "H....*..C...CCCC..", N[6]);


    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_porta_aviao1(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum porta-avião pra afundar nesta casa!", matriz(mapa)[2][1] == 'P');
    afunda_destroyer(mapa, 1, 2, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, ".*.....DD.....H..P", N[2]);
    CuAssertStrEquals(tc, "..*..C......D....P", N[3]);
    CuAssertStrEquals(tc, "H..*..C...D..D.S.P", N[4]);
    CuAssertStrEquals(tc, ".H..*..C..D......P", N[5]);
    CuAssertStrEquals(tc, "H....*..C...CCCC..", N[6]);


    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_cruzador4(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum cruzador pra afundar nesta casa!", matriz(mapa)[6][15] == 'C');
    afunda_destroyer(mapa, 15, 6, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "H....P..C...****..", N[6]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_cruzador3(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum cruzador pra afundar nesta casa!", matriz(mapa)[6][12] == 'C');
    afunda_destroyer(mapa, 12, 6, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "H....P..C...****..", N[6]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_cruzador2(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum cruzador pra afundar nesta casa!", matriz(mapa)[6][8] == 'C');
    afunda_destroyer(mapa, 8, 6, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "..P..*......D....P", N[3]);
    CuAssertStrEquals(tc, "H..P..*...D..D.S.P", N[4]);
    CuAssertStrEquals(tc, ".H..P..*..D......P", N[5]);
    CuAssertStrEquals(tc, "H....P..*...CCCC..", N[6]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_cruzador1(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 3);
    CuAssert(tc, "Não tem nenhum cruzador pra afundar nesta casa!", matriz(mapa)[4][6] == 'C');
    afunda_destroyer(mapa, 6, 4, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "..P..*......D....P", N[3]);
    CuAssertStrEquals(tc, "H..P..*...D..D.S.P", N[4]);
    CuAssertStrEquals(tc, ".H..P..*..D......P", N[5]);
    CuAssertStrEquals(tc, "H....P..*...CCCC..", N[6]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_destroyer4(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 1);
    CuAssert(tc, "Não tem nenhum destroyer pra afundar nesta casa!", matriz(mapa)[2][1] == 'D');
    afunda_destroyer(mapa, 1, 2, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "**.DD...", N[2]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
}

void test_afunda_destroyer3(CuTest *tc) {
    Mapa *mapa;
    char **N;

    mapa = get_mapa(tc, 1);
    CuAssert(tc, "Não tem nenhum destroyer pra afundar nesta casa!", matriz(mapa)[2][3] == 'D');
    afunda_destroyer(mapa, 3, 2, 0);

    N = str_vec(mapa);
    CuAssertStrEquals(tc, "DD.**...", N[2]);

    libera_matriz(N, linhas(mapa));
    libera_mapa(mapa);
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
