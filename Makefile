CXX=g++
CXXFLAGS=-std=c++14 -MMD
OBJECTS=main.o grid.o cell.o block.o iblock.o jblock.o lblock.o oblock.o tblock.o sblock.o zblock.o level.o level0.o level1.o level2.o level4.o score.o display.o textdisplay.o game.o 
DEPENDS=${OBJECTS:.o=.d}
EXEC=test

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
