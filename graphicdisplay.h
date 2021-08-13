#ifndef _GRAPHIC_DISPLAY_H_
#define _GRAPHIC_DISPLAY_H_

#include "basedisplay.h"
#include "window.h"
#include <string>

class GraphicDisplay : public BaseDisplay{
    Xwindow *w;       //display window
    const int height; //height of display
    const int width;  //width of display

    void printCell(char type, int x, int y); //print out the cell at position (x,y)
    void printBoard();                       //helper function of printNormally()
    void printNext(int x, int y, char type); //print the next upcoming block
    void clearWindow();                      //clearing block's previous position's color
    void FirstBoardBlind();                  //helper function of printBlindPlayer1()
    void SecondBoardBlind();                 //helper function of printBlindPlayer2()

public:
    GraphicDisplay(Grid *g1, Grid *g2); //constructor
    ~GraphicDisplay();                  //destructor
    void printNormally() override;      //print board when no one is blinded
    void printBlindPlayer1() override;  //print board when player 1 is blinded
    void printBlindPlayer2() override;  //print board when player 2 is blinded
};

#endif
