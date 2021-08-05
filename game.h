#ifndef _GAME_H_
#define _GAME_H_
#include "grid.h"
#include "block.h"
using namespace std;

class Game{

    int level;
    int score1;
    int score2;
    Grid board1;
    Grid board2;

  public:
    Game();
    void start(); //start game
    void restart(); //restart game
    void end(); //end game


};


#endif
