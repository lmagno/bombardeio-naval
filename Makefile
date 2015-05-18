CC=gcc
CFLAGS=
MAIN=test
SRC=./src/
SOURCES=$(SRC)test.c
LIBS= barco matriz mapa
DEPS= $(LIBS:%=$(SRC)lib%.a) $(LIBS:%=$(SRC)lib%.h)
LFLAGS= $(LIBS:%=-l%)

.PHONY: all clean very-clean

all: $(MAIN)

$(MAIN): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) -static -o $(MAIN) $(SRC)$(MAIN).c -L$(SRC) $(LFLAGS)

.o.a:
	ar rcs $@ $<


clean:
	rm -f src/*.a src/*.o

very-clean:
	rm -f $(MAIN) src/*.a src/*.o
