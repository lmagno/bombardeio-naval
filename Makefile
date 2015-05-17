CC=gcc
CFLAGS=
SRC=./src/
SOURCES=$(SRC)test.c
LFLAGS= -lmatriz

MATRIZDIR=$(SRC)
MATRIZC=$(MATRIZDIR)libmatriz.c
MATRIZH=$(MATRIZC:.c=.h)
MATRIZO=$(MATRIZC:.c=.o)
MATRIZLIB=$(MATRIZC:.c=.a)

all: test

test: $(SOURCES) $(MATRIZLIB) $(MATRIZH)
	$(CC) $(CFLAGS) -static -o test $(SRC)test.c -L$(MATRIZDIR) $(LFLAGS)

.o.a:
	ar rcs $@ $<

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	rm test src/*.a
