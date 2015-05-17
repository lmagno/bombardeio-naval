CC=gcc
CFLAGS=
SRC=./src/
SOURCES=$(SRC)test.c
LFLAGS= -l$(MATRIZ) -l$(BARCO)
MAIN=test

MATRIZDIR=$(SRC)
MATRIZ=matriz
MATRIZC=$(MATRIZDIR)lib$(MATRIZ).c
MATRIZH=$(MATRIZC:.c=.h)
MATRIZO=$(MATRIZC:.c=.o)
MATRIZLIB=$(MATRIZC:.c=.a)

BARCO=barco
BARCODIR=$(SRC)
BARCOC=$(BARCODIR)lib$(BARCO).c
BARCOH=$(BARCOC:.c=.h)
BARCOO=$(BARCOC:.c=.o)
BARCOLIB=$(BARCOC:.c=.a)

all: test

$(MAIN): $(SOURCES) $(MATRIZLIB) $(MATRIZH) $(BARCOLIB) $(BARCOH)
	$(CC) $(CFLAGS) -static -o $(MAIN) $(SRC)$(MAIN).c -L$(SRC) $(LFLAGS)

.o.a:
	ar rcs $@ $<

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm -f test src/*.a src/*.o
