#include "graphicdisplay.h"

using namespace std;

GraphicDisplay::GraphicDisplay(Grid *g1, Grid *g2) : 
BaseDisplay{g1,g2}
,w{new Xwindow(650, 800)}
,height{20}
,width{20}
,blind{0} 
{}

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
		case '\0' :
			break;
		case '*' :
			w->fillRectangle(x, y, width, height, Xwindow::Brown);
			break;
		default :
			w->fillRectangle(x, y, width, height, Xwindow::Grey);
			break;
	}
}

void GraphicDisplay::clearWindow() {
	w->fillRectangle(0, 0, 30 * width, height * 34, Xwindow::White);
}

void GraphicDisplay::printBoard() {	
	int nrows = 18;
	int ncols = 11;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			printCell(g1->getCell(i, j)->getType(), (j + 4) * width, (i + 7) * height);
		}
	}

	int buffer = width * 12;
	 for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
                        printCell(g2->getCell(i, j)->getType(), (j + 4) * width + buffer , (i + 7) * height);
                }
        }
}

void GraphicDisplay::FirstBoardBlind() {
        int nrows = 18;
        int ncols = 11;
        for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
			if (i > 1 && i < 12 && j > 1 && j < 9) {
				printCell('+', (j + 4) * width, (i + 7) * height);
			} else {
                        	printCell(g1->getCell(i, j)->getType(), (j + 4) * width, (i + 7) * height);
			}
                }
        }

        int buffer = width * 12;
         for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
                        printCell(g2->getCell(i, j)->getType(), (j + 4) * width + buffer , (i + 7) * height);
                }
        }
}

void GraphicDisplay::SecondBoardBlind() {
        int nrows = 18;
        int ncols = 11;
        for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
			printCell(g1->getCell(i, j)->getType(), (j + 4) * width, (i + 7) * height);
                }
        }
        int buffer = width * 12;
         for (int i = 0; i < nrows; i++) {
                for (int j = 0; j < ncols; j++) {
			if (i > 1 && i < 12 && j > 1 && j < 9) {
				printCell('+', (j + 4) * width + buffer , (i + 7) * height);
			} else {
                        	printCell(g2->getCell(i, j)->getType(), (j + 4) * width + buffer , (i + 7) * height);
			}
                }
        }
}

void GraphicDisplay::printNext(int x, int y, char type) {
	switch (type) {
                case 'I' :
                        w->fillRectangle(x, y, width, height, Xwindow::Red);
			w->fillRectangle(x + width, y, width, height, Xwindow::Red);
			w->fillRectangle(x + width * 2, y, width, height, Xwindow::Red);
			w->fillRectangle(x + width * 3, y, width, height, Xwindow::Red);
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
			w->fillRectangle(x + width, y - height, width, height, Xwindow::Purple);
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

void GraphicDisplay::printNormally() {
	clearWindow();
	w->drawString(width * 4, height * 2, "Level: " + to_string(g1->getLevelNum()));
	w->drawString(width * 16, height * 2, "Level: " + to_string(g2->getLevelNum())); 
	w->drawString(width * 4, height * 3, "Score: " + to_string(g1->getScore()));
	w->drawString(width * 16, height * 3, "Score: " + to_string(g2->getScore()));
	printBoard();
	w->drawString(width * 4, height * 27, "Next: ");
	w->drawString(width * 16, height * 27, "Next: ");
	printNext(width * 4, height * 30, g1->getNextBlock()->getType());
	printNext(width * 16, height * 30, g2->getNextBlock()->getType());
}

void GraphicDisplay::printBlindPlayer1() {
	clearWindow();
        w->drawString(width * 4, height * 2, "Level: " + to_string(g1->getLevelNum()));
        w->drawString(width * 16, height * 2, "Level: " + to_string(g2->getLevelNum()));
        w->drawString(width * 4, height * 3, "Score: " + to_string(g1->getScore()));
        w->drawString(width * 16, height * 3, "Score: " + to_string(g2->getScore()));
        FirstBoardBlind();
        w->drawString(width * 4, height * 27, "Next: ");
        w->drawString(width * 16, height * 27, "Next: ");
        printNext(width * 4, height * 30, g1->getNextBlock()->getType());
        printNext(width * 16, height * 30, g2->getNextBlock()->getType());
}

void GraphicDisplay::printBlindPlayer2() {
        clearWindow();
        w->drawString(width * 4, height * 2, "Level: " + to_string(g1->getLevelNum()));
        w->drawString(width * 16, height * 2, "Level: " + to_string(g2->getLevelNum()));
        w->drawString(width * 4, height * 3, "Score: " + to_string(g1->getScore()));
        w->drawString(width * 16, height * 3, "Score: " + to_string(g2->getScore()));
        SecondBoardBlind();
        w->drawString(width * 4, height * 27, "Next: ");
        w->drawString(width * 16, height * 27, "Next: ");
        printNext(width * 4, height * 30, g1->getNextBlock()->getType());
        printNext(width * 16, height * 30, g2->getNextBlock()->getType());
}

