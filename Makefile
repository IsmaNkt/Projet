all: main

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

mainJO: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug



#..
#
#..
#
#creerFichier.o : creerFichier.c fichierheaders.h
#	gcc -c creerFichier.c -o creerFichier.o
#
#
#exec : mainJO.o creerFichier.o
#	gcc mainJO.o creerFichier.o -o exec

