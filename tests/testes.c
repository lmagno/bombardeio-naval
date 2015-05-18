#include <stdio.h>
#include "./cutest-1.5/CuTest.h"
#include "../src/libmatriz.h"
#include "../src/libmapa.h"

CuSuite* test_matriz_get_suite();
CuSuite* test_mapa_get_suite();

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, test_matriz_get_suite());
    CuSuiteAddSuite(suite, test_mapa_get_suite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

}

int main(int argc, char *argv[]) {
    RunAllTests();
    return 0;
}
