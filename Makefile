CC=gcc
CFLAGS=
MAIN=test
SRC=./src/
SOURCES=$(SRC)$(MAIN).c
LIBS= barco matriz mapa
DEPS= $(LIBS:%=$(SRC)lib%.a) $(LIBS:%=$(SRC)lib%.h)
LFLAGS= $(LIBS:%=-l%)

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

TEST=testes
TESTDIR=./tests/
TESTSOURCES=$(TESTDIR)$(TEST).c

testes: $(TESTSOURCES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TEST) $(TESTSOURCES) -L$(SRC) $(LFLAGS)
	./testes
