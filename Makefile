CC = gcc
SRC = src/
BUILD = build/src/
BUILDT = build/test/
CFLAGS = -Wall -Wextra -std=c99 -pedantic $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib) -lm
HEAD = headers/
OBJECTS = ${BUILD}main.o ${BUILD}utils.o ${BUILD}map.o ${BUILD}scene.o ${BUILD}map_elem_parser.o
TEST = tests/

all: main

main: ${OBJECTS}
		${CC} -o $@ ${OBJECTS} ${LIBS}

${BUILD}main.o: ${SRC}main.c ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}utils.o: ${SRC}utils.c ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}map.o: ${SRC}map.c ${HEAD}map.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}scene.o: ${SRC}scene.c ${HEAD}scene.h ${HEAD}utils.h ${HEAD}map_data.h
	@mkdir -p ${BUILD}
	${CC} ${CFLAGS} -c $< -o $@

${BUILD}map_elem_parser.o: ${SRC}map_elem_parser.c ${HEAD}map_elem_parser.h ${HEAD}map_data.h ${HEAD}map.h
	@mkdir -p ${BUILD}
	${CC} ${FLAGS} -c $< -o $@



test: ${BUILDT}test_parser.o ${BUILD}map_elem_parser.o 
	${CC} -o $@ $^ ${LIBS}

${BUILDT}test_parser.o: ${TEST}test_parser.c ${HEAD}map_elem_parser.h ${HEAD}map_data.h 
	@mkdir -p ${BUILDT}
	${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -rf build/
		rm main
		rm test