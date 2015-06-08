CC:=gcc
CFLAGS:=-g -Wall
MAIN:=main
SRC:=./src/
SOURCES:=$(SRC)$(MAIN).c
LIBS:= embarcacoes barco mapa utils status
DEPS:= $(LIBS:%=$(SRC)lib%.a) $(LIBS:%=$(SRC)lib%.h)
LFLAGS:= $(LIBS:%=-l%)

.PHONY: all clean very-clean

all: $(MAIN)

$(MAIN): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) -static -o $(MAIN) $(SOURCES) -L$(SRC) $(LFLAGS)

.o.a:
	ar rcs $@ $<

clean:
	rm -f src/*.a src/*.o

very-clean:
	rm -f $(TEST) $(MAIN) src/*.a src/*.o

TEST:=testes
TESTDIR:=./tests/
TESTSOURCES:=$(wildcard $(TESTDIR)*.c)
CUTESTDIR=./tests/cutest-1.5/
CUTESTDEPS=$(CUTESTDIR)CuTest.c $(CUTESTDIR)CuTest.h

testes: $(TESTSOURCES) $(DEPS) $(CUTESTDEPS)
	$(CC) $(CFLAGS) -o $(TEST) $(TESTSOURCES) $(CUTESTDEPS) -L$(SRC) $(LFLAGS)
	./testes
