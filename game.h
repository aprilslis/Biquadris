#ifndef _GAME_H_
#define _GAME_H_
#include "grid.h"
#include "score.h"
#include "textdisplay.h"
#include <vector>
using namespace std;

class Game{

    string file1;
    string file2;

    Grid board1;
    Grid board2;

    TextDisplay textdisplay;

  public:
    Game();
    void start(int startLevel=0); //start game
    void restart(); //restart game
    void end(int winner=0); //end game

    void drawText();
    void drawGraphic();

    void setFile1(string file);
    void setFile2(string file);
    void setSeed(int seed);


};


#endif
