#include "graphicdisplay.h"

using namespace std;

GraphicDisplay::GraphicDisplay(Grid *g1, Grid *g2) : BaseDisplay{g1,g2}, w{new Xwindow()}, height{10}, width{10} {}

GraphicDisplay::~GraphicDisplay() {
	delete w;
}

void GraphicDisplay::printCell(char type, int x, int y) {
	switch (type) {
		case 'I' : 
			w->fillRectangle(x, y, width, height, Xwindow::Red);
			break;
		case 'J' :
			w->fillRectangle(x, y, width, height, Xwindow::Orange);
			break;
		case 'L' :
			w->fillRectangle(x, y, width, height, Xwindow::Blue);
			break;
		case 'O' :
			w->fillRectangle(x, y, width, height, Xwindow::Yellow);
			break;
		case 'S' :
			w->fillRectangle(x, y, width, height, Xwindow::Purple);
			break;
		case 'Z' :
			w->fillRectangle(x, y, width, height, Xwindow::Green);
			break;
		case 'T' : 
			w->fillRectangle(x, y, width, height, Xwindow::Black);
			break;
		case '\0':
			break;
		default :
			w->fillRectangle(x, y, width, height, Xwindow::Brown);
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

void GraphicDisplay::printNext(int x, int y, char type) {
	switch (type) {
                case 'I' :
                        w->fillRectangle(x, y, width, height, Xwindow::Red);
			w->fillRectangle(x + width, y, height, Xwindow::Red);
			w->fillRectangle(x + width * 2, y, height, Xwindow::Red);
			w->fillRectangle(x + width * 3, y, height, Xwindow::Red);
                	break;
                case 'J' :
                        w->fillRectangle(x, y - width, width, height, Xwindow::Orange);
			w->fillRectangle(x, y, width, height, Xwindow::Orange);
			w->fillRectangle(x + width, y, width, height, Xwindow::Orange);
			w->fillRectangle(x + width * 2, y, width, height, Xwindow::Orange);
                        break;
                case 'L' :
                        w->fillRectangle(x + width * 2, y - height, width, height, Xwindow::Blue);
			w->fillRectangle(x, y, width, height, Xwindow::Blue);
                        w->fillRectangle(x + width, y, width, height, Xwindow::Blue);
                        w->fillRectangle(x + width * 2, y, width, height, Xwindow::Blue);
                        break;
                case 'O' :
                        w->fillRectangle(x, y - height, width, height, Xwindow::Yellow);
			w->fillRectangle(x + width, y - height, width, height, Xwindow::Yellow);
			w->fillRectangle(x, y, width, height, Xwindow::Yellow);
			w->fillRectangle(x + width, y, width, height, Xwindow::Yellow);
                        break;
                case 'S' :
			w->fillRectangle(x + width * 2, y - height, width, height, Xwindow::Purple);
			w->fillRectangle(x + width, y, width, height, Xwindow::Purple);
			w->fillRectangle(x, y, width, height, Xwindow::Purple);
                        w->fillRectangle(x + width, y, width, height, Xwindow::Purple);
                        break;
                case 'Z' :
			w->fillRectangle(x, y - height, width, height, Xwindow::Green);
			w->fillRectangle(x + width, y - height, width, height, Xwindow::Green);
			w->fillRectangle(x + width, y, width, height, Xwindow::Green);
                        w->fillRectangle(x + width * 2, y, width, height, Xwindow::Green);
                        break;
                case 'T' :
                        w->fillRectangle(x, y - height, width, height, Xwindow::Black);
			w->fillRectangle(x + width, y - height, width, height, Xwindow::Black);
			w->fillRectangle(x + width * 2, y - height, width, height, Xwindow::Black);
			w->fillRectangle(x + width, y, width, height,Xwindow::Black);
                        break;
                case '\0':
                        break;
                default :
                        w->fillRectangle(x, y, width, height, Xwindow::Brown);
        }

}

void GraphicDisplay::printDisplay() {
	w->drawString(0, 0, "Level: " + to_string(g1->getLevelNum()));
	w->drawString(width * 12, 0, "Level: " + to_string(g2->getLevelNum())); 
	w->drawString(0, height, "Score: " + to_string(g1->getScore()));
	w->drawString(width * 12, height, "Score: " + to_string(g2->getScore()));
	printBoard();
	w->drawString(0, height * 22, "Next: ");
	w->drawString(width * 12, height * 22, "Next: ");
	printNext(0, height * 24, g1->getNextBlock()->getType());
	printNext(width * 12, height * 24, g2->getNextBlock()->getType());
}
