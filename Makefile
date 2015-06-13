CC:=gcc
CFLAGS:=-g -Wall
MAIN:=main
SRC:=./src/
SOURCES:=$(SRC)$(MAIN).c
LIBS:= embarcacoes barco mapa utils status
DEPS:= $(LIBS:%=$(SRC)lib%.so) $(LIBS:%=$(SRC)lib%.h)
LFLAGS:= $(LIBS:%=-l%) -lm -lXpm -lX11 

.PHONY: all clean very-clean

all: $(MAIN)


$(MAIN): $(SOURCES) $(DEPS) xwc.o
	$(CC) $(CFLAGS) -Wl,-rpath=$(SRC) -o $(MAIN) $(SOURCES) -L$(SRC) $(LFLAGS) 

%.so: %.o
	$(CC) -shared -o $@ $<

xwc.o : xwc.c

xwc.c: 
	$(CC) -g -Wall  -I  -O2 -o -lm -lXpm -lX11

%.o: %.c
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

clean:
	rm -f src/*.o src/*.so

very-clean:
	rm -f $(TEST) $(MAIN) src/*.o src/*.so

TEST:=testes
TESTDIR:=./tests/
TESTSOURCES:=$(wildcard $(TESTDIR)*.c)
CUTESTDIR=./tests/cutest-1.5/
CUTESTDEPS=$(CUTESTDIR)CuTest.c $(CUTESTDIR)CuTest.h

testes: $(TESTSOURCES) $(DEPS) $(CUTESTDEPS)
	$(CC) $(CFLAGS) -o $(TEST) $(TESTSOURCES) $(CUTESTDEPS) -Wl,-rpath=$(SRC) -L$(SRC) $(LFLAGS)
	./testes
