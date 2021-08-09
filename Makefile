CXX=g++
CXXFLAGS=-std=c++14 -lX11 -L/usr/X11/lib -I/usr/X11/include -MMD
CXXFLAGS=-std=c++14 -MMD
OBJECTS=main.o grid.o cell.o block.o iblock.o jblock.o lblock.o oblock.o tblock.o sblock.o zblock.o level.o level0.o level1.o level2.o level4.o score.o basedisplay.o textdisplay.o game.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=test

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

graphicdisplay.o: graphicdisplay.h graphicdisplay.cc
	g++ -std=c++14 -c graphicdisplay.cc -lX11 -L/usr/X11/lib -I/usr/X11/include

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
