#include <stdio.h>
#include <stdlib.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libmatriz.h"

void test_aloca_matriz_1x1(CuTest *tc);
void test_aloca_matriz_1000x1000(CuTest *tc);

CuSuite* test_matriz_get_suite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_aloca_matriz_1x1);
    SUITE_ADD_TEST(suite, test_aloca_matriz_1000x1000);
    return suite;
}

void test_aloca_matriz_1x1(CuTest *tc) {
    int m = 1,
        n = 1;

    char **M = aloca_matriz(m, n);
    CuAssertPtrNotNull(tc, M);

    free(M);
}

void test_aloca_matriz_1000x1000(CuTest *tc) {
    int m = 1000,
        n = 1000;

    char **M = aloca_matriz(m, n);
    CuAssertPtrNotNull(tc, M);

    free(M);
}
