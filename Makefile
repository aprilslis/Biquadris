CXX=g++
CXXFLAGS=-std=c++14 -MMD -Werror=vla
OBJECTS=main.o grid.o cell.o starblock.o block.o iblock.o jblock.o lblock.o oblock.o tblock.o sblock.o zblock.o level.o level0.o level1.o level2.o level3.o level4.o score.o basedisplay.o graphicdisplay.o textdisplay.o window.o game.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=biquadris

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} -lX11 

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
