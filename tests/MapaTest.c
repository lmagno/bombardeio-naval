#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libmapa.h"
#include "../src/libmatriz.h"

void test_mapa1(CuTest *tc);
void test_mapa2(CuTest *tc);
void test_mapa3(CuTest *tc);
void test_mapa4(CuTest *tc);

CuSuite* test_mapa_get_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_mapa1);
    SUITE_ADD_TEST(suite, test_mapa2);
    SUITE_ADD_TEST(suite, test_mapa3);
    SUITE_ADD_TEST(suite, test_mapa4);
    return suite;
}

void test_mapa1(CuTest *tc) {
    Mapa *mapa;
    char **M, **N;
    char path[50];
    int i;
    int m = 5,
        n = 8;

    strcpy(path, "./mapas/mapa1.dat");
    FILE *arq = fopen(path, "r");
    CuAssertPtrNotNull(tc, arq);

    mapa = leia_mapa_arq(arq);
    CuAssertPtrNotNull(tc, mapa);
    CuAssertIntEquals(tc, m, linhas(mapa));
    CuAssertIntEquals(tc, n, colunas(mapa));

    M = matriz(mapa);
    N = aloca_matriz(m, n + 1);

    for (i = 0; i < m; i++){
        strncpy(N[i], M[i], n);
        N[i][n] = '\0';
    }

    CuAssertStrEquals(tc, "CCCC.HBH", N[0]);
    CuAssertStrEquals(tc, "......H.", N[1]);
    CuAssertStrEquals(tc, "DD.DD...", N[2]);
    CuAssertStrEquals(tc, "......H.", N[3]);
    CuAssertStrEquals(tc, "CCCC.H.H", N[4]);

    libera_mapa(mapa);
    libera_matriz(N, m);
    fclose(arq);
}

void test_mapa2(CuTest *tc) {
    Mapa *mapa;
    char **M, **N;
    char path[50];
    int i;
    int m = 6,
        n = 13;

    strcpy(path, "./mapas/mapa2.dat");
    FILE *arq = fopen(path, "r");
    CuAssertPtrNotNull(tc, arq);

    mapa = leia_mapa_arq(arq);
    CuAssertPtrNotNull(tc, mapa);
    CuAssertIntEquals(tc, m, linhas(mapa));
    CuAssertIntEquals(tc, n, colunas(mapa));

    M = matriz(mapa);
    N = aloca_matriz(m, n + 1);

    for (i = 0; i < m; i++){
        strncpy(N[i], M[i], n);
        N[i][n] = '\0';
    }

    CuAssertStrEquals(tc, "..DD.B.H.H..H", N[0]);
    CuAssertStrEquals(tc, ".P......H..H.", N[1]);
    CuAssertStrEquals(tc, "..P...C.....H", N[2]);
    CuAssertStrEquals(tc, "H..P...C.....", N[3]);
    CuAssertStrEquals(tc, ".H..P...C..D.", N[4]);
    CuAssertStrEquals(tc, "H....P...C.D.", N[5]);

    libera_mapa(mapa);
    libera_matriz(N, m);
    fclose(arq);
}

void test_mapa3(CuTest *tc) {
    Mapa *mapa;
    char **M, **N;
    char path[50];
    int i;
    int m = 14,
        n = 18;

    strcpy(path, "./mapas/mapa3.dat");
    FILE *arq = fopen(path, "r");
    CuAssertPtrNotNull(tc, arq);

    mapa = leia_mapa_arq(arq);
    CuAssertPtrNotNull(tc, mapa);
    CuAssertIntEquals(tc, m, linhas(mapa));
    CuAssertIntEquals(tc, n, colunas(mapa));

    M = matriz(mapa);
    N = aloca_matriz(m, n + 1);

    for (i = 0; i < m; i++){
        strncpy(N[i], M[i], n);
        N[i][n] = '\0';
    }

    CuAssertStrEquals(tc, ".CCCC.B..H.H..H...", N[0]);
    CuAssertStrEquals(tc, "..........H..H...P", N[1]);
    CuAssertStrEquals(tc, ".P.....DD.....H..P", N[2]);
    CuAssertStrEquals(tc, "..P..C......D....P", N[3]);
    CuAssertStrEquals(tc, "H..P..C...D..D.S.P", N[4]);
    CuAssertStrEquals(tc, ".H..P..C..D......P", N[5]);
    CuAssertStrEquals(tc, "H....P..C...CCCC..", N[6]);
    CuAssertStrEquals(tc, "..S.......C.......", N[7]);
    CuAssertStrEquals(tc, ".........C..S.H.H.", N[8]);
    CuAssertStrEquals(tc, ".PPPPP..C......H..", N[9]);
    CuAssertStrEquals(tc, ".......C..D......S", N[10]);
    CuAssertStrEquals(tc, "....D....D...DD...", N[11]);
    CuAssertStrEquals(tc, ".H..D..D..........", N[12]);
    CuAssertStrEquals(tc, "H.H...D..S..PPPPP.", N[13]);

    libera_mapa(mapa);
    libera_matriz(N, m);
    fclose(arq);
}

void test_mapa4(CuTest *tc) {
    Mapa *mapa;
    char **M, **N;
    char path[50];
    int i;
    int m = 6,
        n = 15;

    strcpy(path, "./mapas/mapa4.dat");
    FILE *arq = fopen(path, "r");
    CuAssertPtrNotNull(tc, arq);

    mapa = leia_mapa_arq(arq);
    CuAssertPtrNotNull(tc, mapa);
    CuAssertIntEquals(tc, m, linhas(mapa));
    CuAssertIntEquals(tc, n, colunas(mapa));

    M = matriz(mapa);
    N = aloca_matriz(m, n + 1);

    for (i = 0; i < m; i++){
        strncpy(N[i], M[i], n);
        N[i][n] = '\0';
    }

    CuAssertStrEquals(tc, "S...C...B.H.H..", N[0]);
    CuAssertStrEquals(tc, "..P..C..S..H..H", N[1]);
    CuAssertStrEquals(tc, "...P..C......H.", N[2]);
    CuAssertStrEquals(tc, "....P..C.DD...H", N[3]);
    CuAssertStrEquals(tc, "H.H..P.........", N[4]);
    CuAssertStrEquals(tc, ".H....P..CCCC.S", N[5]);

    libera_mapa(mapa);
    libera_matriz(N, m);
    fclose(arq);
}
