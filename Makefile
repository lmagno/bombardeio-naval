CC=gcc
CFLAGS=
SRC=./src/
SOURCES=$(SRC)test.c
LFLAGS= -lmatriz
MAIN=test

MATRIZDIR=$(SRC)
MATRIZC=$(MATRIZDIR)libmatriz.c
MATRIZH=$(MATRIZC:.c=.h)
MATRIZO=$(MATRIZC:.c=.o)
MATRIZLIB=$(MATRIZC:.c=.a)

all: test

$(MAIN): $(SOURCES) $(MATRIZLIB) $(MATRIZH)
	$(CC) $(CFLAGS) -static -o $(MAIN) $(SRC)$(MAIN).c -L$(MATRIZDIR) $(LFLAGS)

.o.a:
	ar rcs $@ $<

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm test src/*.a
