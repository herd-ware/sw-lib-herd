LIB = sys
CFILES = ${wildcard *.c}
SFILES = ${wildcard *.S}
CSRCS = ${patsubst %.c, %, ${CFILES}}
SSRCS = ${patsubst %.S, %, ${SFILES}}

INCLUDE = -I../pltf/

all: ${LIB}.a

${CSRCS}: ${CFILES}
	mkdir -p obj/
	${CC} $(CFLAGS) ${INCLUDE} -c $@.c -o obj/$@.o

${SSRCS}: ${SFILES}
	mkdir -p obj/
	${CC} $(CFLAGS) -c $@.S -o obj/$@.o

${LIB}.a: ${CSRCS} ${SSRCS}
	${AR} rcs $@ obj/*
