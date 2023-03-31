INCLUDE = -Isrc/pltf/
INCLUDE += -Isrc/sys/

LIB_HERD_LIBS = sys

build-dir:
	mkdir -p ${PRJ_DIR}/obj
	mkdir -p ${PRJ_DIR}/lib

${LIB_HERD_LIBS}: build-dir
	make -C src/$@ all
	mv src/$@/obj/*.o obj/
	mv src/$@/$@.a lib/

all: ${LIB_HERD_LIBS} 
	${CC} $(CFLAGS) ${INCLUDE} -c src/lib-herd.c -o obj/lib-herd.o
	${AR} rcs lib/lib-herd.a obj/*.o

clean:
	rm -rf obj/
	rm -rf lib/