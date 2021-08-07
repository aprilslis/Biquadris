#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Grid *g1, Grid *g2) : Display{g1,g2}, height{18} {}

string TextDisplay::topTextBlock(char next) {
        switch(next) {
                case 'I' :
                        return "    ";
                case 'J' :
                        return "J   ";
                case 'L' :
                        return "  L ";
                case 'O' :
                        return "OO  ";
                case 'S' :
                        return " SS ";
                case 'Z' :
                        return "ZZ  ";
                case 'T' :
                        return "TTT ";
                default :
                        return "    ";
        }
}

string TextDisplay::lowTextBlock(char next) {
        switch(next) {
                case 'I' :
                        return "IIII";
                case 'J' :
                        return "JJJ ";
                case 'L' :
                        return "LLL ";
                case 'O' :
                        return "OO  ";
                case 'S' :
                        return "SS  ";
                case 'Z' :
                        return " ZZ ";
                case 'T' :
                        return " T  ";
                default :
                        return "    ";
        }
}

void TextDisplay::printDisplay() {
        string spacing = "               ";
        string slevel = "Level:    ";
        string sscore = "Score:    ";
        string snext = "Next:     ";
        string line = "___________";
        cout << slevel << g1->getLevelNum() << spacing << slevel << g2->getLevelNum() << endl;
        cout << sscore << g1->getScore() << spacing << sscore << g2->getScore() << endl;
        cout << line << spacing << line << endl;
        // Grid *b1 = g1->getGrid();
        // Grid *b2 = g2->getGrid();
        for (int i = 0; i  < height; i++) {
                cout << g1->printRow(i) << spacing << g2->printRow(i) << endl;
        }
        cout << line << spacing << line << endl;
        string ttb1 = topTextBlock(g1->getNextBlock()->getType()) + "       ";
        string ttb2 = topTextBlock(g2->getNextBlock()->getType()) + "       ";
        string ltb1 = lowTextBlock(g1->getNextBlock()->getType()) + "       ";
        string ltb2 = lowTextBlock(g2->getNextBlock()->getType()) + "       ";
        cout << snext << spacing << snext << endl;
        cout << ttb1 << spacing << ttb2 << endl;
        cout << ltb1 << spacing << ltb2 << endl;
}

