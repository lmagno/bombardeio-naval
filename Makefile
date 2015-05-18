CC=gcc
CFLAGS=
SRC=./src/
SOURCES=$(SRC)test.c
LFLAGS=  -l$(MAPA) -l$(MATRIZ) -l$(BARCO)
OBJS= $(MATRIZO) $(MAPAO) $(BARCOO)
MAIN=test

MATRIZ=matriz
MATRIZDIR=$(SRC)
MATRIZC=$(MATRIZDIR)lib$(MATRIZ).c
MATRIZH=$(MATRIZC:.c=.h)
MATRIZO=$(MATRIZC:.c=.o)
MATRIZLIB=$(MATRIZC:.c=.a)

MAPA=mapa
MAPADIR=$(SRC)
MAPAC=$(MAPADIR)lib$(MAPA).c
MAPAH=$(MAPAC:.c=.h)
MAPAO=$(MAPAC:.c=.o)
MAPALIB=$(MAPAC:.c=.a)

BARCO=barco
BARCODIR=$(SRC)
BARCOC=$(BARCODIR)lib$(BARCO).c
BARCOH=$(BARCOC:.c=.h)
BARCOO=$(BARCOC:.c=.o)
BARCOLIB=$(BARCOC:.c=.a)

all: $(MAIN)

$(MAIN): $(SOURCES) $(MATRIZLIB) $(MATRIZH) $(BARCOLIB) $(BARCOH) $(MAPALIB) $(MAPAH)
	$(CC) $(CFLAGS) -static -o $(MAIN) $(SRC)$(MAIN).c -L$(SRC) $(LFLAGS)

.o.a:
	ar rcs $@ $<

.PHONY: clean

clean:
	rm -f $(MAIN) src/*.a src/*.o
