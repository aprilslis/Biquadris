#ifndef _GRAPHIC_DISPLAY_H_
#define _GRAPHIC_DISPLAY_H_

#include "basedisplay.h"
#include "window.h"
#include <string>

class GraphicDisplay: public BaseDisplay {
	Xwindow *w;
        const int height;
        const int width;
	void printCell(char type, int x, int y);
	void printBoard();
	void printNext(int x, int y, char type);
	void clearWindow();
	void FirstBoardBlind();
	void SecondBoardBlind();
	public:
	GraphicDisplay(Grid *g1, Grid *g2);
	void printDisplay() override;
	void printBlindPlayer1() override;
	void printBlindPlayer2() override;
	~GraphicDisplay();
};

#endif
