#ifndef _TEXT_DISPLAY_H_
#define _TEXT_DISPLAY_H_

#include "basedisplay.h"
#include <string>

class TextDisplay : public BaseDisplay{
    int height;                               //height of game baord
    std::string topTextBlock(char next);      //top row of block
    std::string lowTextBlock(char next);      //bottom row of block
    std::string printBlind(Grid *g, int row); //helper function of printBlindPlayer1() and printBlindPlayer1()

public:
    TextDisplay(Grid *g1, Grid *g2);   //constructor
    void printNormally() override;     //print board when no one is blindeds
    void printBlindPlayer1() override; //print board when player 1 is blinded
    void printBlindPlayer2() override; //print board when player 2 is blinded
};

#endif
