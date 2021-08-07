#ifndef _GAME_H_
#define _GAME_H_
#include "grid.h"
#include "score.h"
#include "textdisplay.h"
#include <vector>
using namespace std;

class Game{

    Score score1;
    Score score2;
    Grid board1;
    Grid board2;

    TextDisplay textdisplay;

  public:
    Game();
    void start(); //start game
    void restart(); //restart game
    void end(int winner=0); //end game

    int getScore1();
    int getScore2();

    void drawText();
    void drawGraphic();


};


#endif
