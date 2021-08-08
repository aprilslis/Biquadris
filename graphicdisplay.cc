#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(Grid *g1, Grid *g2) : w{new XWindow()}, Display(g1, g2) height{10}, width{10} {}


void GraphicDisplay::printCell(char type, int x, int y) {
	switch (type) {
		case 'I' : 
			w->fillRectangle(x, y, width, height, Red);
			break;
		case 'J' :
			w->fillRectangle(x, y, width, height, Orange);
			break;
		case 'L' :
			w->fillRectangle(x, y, width, height, Blue);
			break;
		case 'O' :
			w->fillRectangle(x, y, width, height, Yellow);
			break;
		case 'S' :
			w->fillRectangle(x, y, width, height, Purple);
			break;
		case 'Z' :
			w->fillRectangle(x, y, width, height, Green);
			break;
		case 'T' : 
			w->fillRectangle(x, y, width, height, Black);
			break;
		case '\0':
			break;
		default :
			w->fillRectangle(x, y, width, height, Brown);	
			break;
	}
}

void GraphicDisplay::printBoard() {	
	int nrows = 18;
	int ncols = 11;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			printCell(g1->getCell(i, j)->getType(), j * width, (i + 1) * height + 3);
		}
	}

	 for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
                        printCell(g2->getCell(i, j)->getType(), j * (width + 12), (i + 1) * height + 3);
                }
        }
}

void GraphicDisplay::printNext(int x, int y, int type) {
	switch (type) {
                case 'I' :
                        w->fillRectangle(x, y, width, height, Red);
			w->fillRectangle(x + width, y, height, Red);
			w->fillRectangle(x + width * 2, y, height, Red);
			w->fillRectangle(x + width * 3, y, height, Red);
                	break;
                case 'J' :
                        w->fillRectangle(x, y - width, width, height, Orange);
			w->fillRectangle(x, y, width, height, Orange);
			w->fillRecangle(x + width, y, width, height, Orange);
			w->fillRectangle(x + width * 2, y, width, height, orange);
                        break;
                case 'L' :
                        w->fillRectangle(x + width * 2, y - height, width, height, Blue);
			w->fillRectangle(x, y, width, height, Blue);
                        w->fillRecangle(x + width, y, width, height, Blue);
                        w->fillRectangle(x + width * 2, y, width, height, Blue);
                        break;
                case 'O' :
                        w->fillRectangle(x, y - height, width, height, Yellow);
			w->fillRectangle(x + width, y - height, width, height, Yellow);
			w->fillRectangle(x, y, width, height, Yellow);
			w->fillRectangle(x + width, y, width, height, Yellow);
                        break;
                case 'S' :
			w->fillRectangle(x + width * 2, y - height, width, height, Purple);
			w->fillRectangle(x + width, y, width, height, Purple);
			w->fillRectangle(x, y, width, height, Purple);
                        w->fillRectangle(x + width, y, width, height, Purple);
                        break;
                case 'Z' :
			w->fillRectangle(x, y - height, width, height, Green);
			w->fillRectangle(x + width, y - height, width, height, Green);
			w->fillRectangle(x + width, y, width, height, Green);
                        w->fillRectangle(x + width * 2, y, width, height, Green);
                        break;
                case 'T' :
                        w->fillRectangle(x, y - height, width, height, Black);
			w->fillRectangle(x + width, y - height, width, height, Black);
			w->fillRectangle(x + width * 2, y - height, width, height, Black);
			w->fillRectangle(x + width, y, width, height, Black);
                        break;
                case '\0':
                        break;
                default :
                        w->fillRectangle(x, y, width, height, Brown);
        }

}

void GraphicDisplay::printDisplay() {
	w->drawString(0, 0, "Level: " + (string)g1->getLevel());
	w->drawString(width * 12, 0, "Level: " + (string)g2->getLevel()); 
	w->drawString(0, height, "Score: " + (string)g1->getScore());
	w->drawString(width * 12, height, "Score: " + (string)g2->getScore());
	printBoard();
	w->drawString(0, height * 22, "Next: ");
	w->drawString(width * 12, height * 22, "Next: ");
	printNext(0, height * 24, g1->getNextBlock()->getType());
	printNext(width * 12, height * 24, g2->getNextBlock()->getType());
}
