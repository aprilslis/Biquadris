#ifndef _GAME_H_
#define _GAME_H_
#include "grid.h"
#include "score.h"
#include "textdisplay.h"
#include <vector>

class Game{

    std::stringstream seqFile; //for sequence command
    bool useSeqFile;

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

    void setDefaultFile1(string file);
    void setDefaultFile2(string file);
    void setSeed(int seed);


};


#endif
