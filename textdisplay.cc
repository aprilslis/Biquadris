#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Grid *g1, Grid *g2) : BaseDisplay{g1, g2}, height{18} {}

string TextDisplay::topTextBlock(char next){
    switch (next){
        case 'I':
            return "    ";
        case 'J':
            return "J   ";
        case 'L':
            return "  L ";
        case 'O':
            return "OO  ";
        case 'S':
            return " SS ";
        case 'Z':
            return "ZZ  ";
        case 'T':
            return "TTT ";
        default:
            return "    ";
    }
}

string TextDisplay::lowTextBlock(char next){
    switch (next){
        case 'I':
            return "IIII";
        case 'J':
            return "JJJ ";
        case 'L':
            return "LLL ";
        case 'O':
            return "OO  ";
        case 'S':
            return "SS  ";
        case 'Z':
            return " ZZ ";
        case 'T':
            return " T  ";
        default:
            return "    ";
    }
}

string TextDisplay::printBlind(Grid *g, int row){
    string qmarks = "???????";
    string result = "";
    if (row >= 5 && row <= 14){
        for (int j = 0; j < 2; j++){
            if (g->getCell(row, j)->getType() == '\0'){
                result += " ";
            }
            else{
                result += g->getCell(row, j)->getType();
            }
        }
        result += qmarks;
        for (int j = 9; j < 11; j++){
            result += g->getCell(row, j)->getType();
        }
        return result;
    }
    else{
        return g->printRow(row);
    }
}

void TextDisplay::printNormally(){
    string spacing = "               ";
    string slevel = "Level:    ";
    string sscore = "Score:    ";
    string snext = "Next:     ";
    string line = "-----------";
    cout << endl;
    cout << slevel << g1->getLevelNum() << spacing << slevel << g2->getLevelNum() << endl;
    cout << sscore << g1->getScore() << spacing << sscore << g2->getScore() << endl;
    cout << line << spacing << line << endl;
    for (int i = 0; i < height; i++){
        cout << g1->printRow(i) << spacing << g2->printRow(i) << endl;
    }
    cout << line << spacing << line << endl;

    string ttb1 = topTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ttb2 = topTextBlock(g2->getNextBlock()->getType()) + "       ";
    string ltb1 = lowTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ltb2 = lowTextBlock(g2->getNextBlock()->getType()) + "       ";

    cout << snext << spacing << " " << snext << endl;
    cout << ttb1 << spacing << ttb2 << endl;
    cout << ltb1 << spacing << ltb2 << endl;
}

void TextDisplay::printBlindPlayer1(){
    string spacing = "               ";
    string slevel = "Level:    ";
    string sscore = "Score:    ";
    string snext = "Next:     ";
    string line = "___________";
    cout << endl;
    cout << slevel << g1->getLevelNum() << spacing << slevel << g2->getLevelNum() << endl;
    cout << sscore << g1->getScore() << spacing << sscore << g2->getScore() << endl;
    cout << line << spacing << line << endl;
    for (int i = 0; i < height; i++){
        cout << printBlind(g1, i) << spacing << g2->printRow(i) << endl;
    }
    cout << line << spacing << line << endl;

    string ttb1 = topTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ttb2 = topTextBlock(g2->getNextBlock()->getType()) + "       ";
    string ltb1 = lowTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ltb2 = lowTextBlock(g2->getNextBlock()->getType()) + "       ";

    cout << snext << spacing << " " << snext << endl;
    cout << ttb1 << spacing << ttb2 << endl;
    cout << ltb1 << spacing << ltb2 << endl;
}

void TextDisplay::printBlindPlayer2(){
    string spacing = "               ";
    string slevel = "Level:    ";
    string sscore = "Score:    ";
    string snext = "Next:     ";
    string line = "___________";
    cout << endl;
    cout << slevel << g1->getLevelNum() << spacing << slevel << g2->getLevelNum() << endl;
    cout << sscore << g1->getScore() << spacing << sscore << g2->getScore() << endl;
    cout << line << spacing << line << endl;
    for (int i = 0; i < height; i++){
        cout << g1->printRow(i) << spacing << printBlind(g2, i) << endl;
    }
    cout << line << spacing << line << endl;

    string ttb1 = topTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ttb2 = topTextBlock(g2->getNextBlock()->getType()) + "       ";
    string ltb1 = lowTextBlock(g1->getNextBlock()->getType()) + "       ";
    string ltb2 = lowTextBlock(g2->getNextBlock()->getType()) + "       ";

    cout << snext << spacing << " " << snext << endl;
    cout << ttb1 << spacing << ttb2 << endl;
    cout << ltb1 << spacing << ltb2 << endl;
}
