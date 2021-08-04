CXX=g++
CXXFLAGS=-std=c++14 -MMD
OBJECTS=main.o grid.o cell.o block.o iblock.o jblock.o lblock.o oblock.o tblock.o sblock.o zblock.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=tetris

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
