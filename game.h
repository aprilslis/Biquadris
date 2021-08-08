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

    bool onlyText;
    TextDisplay textdisplay;

    void specialEffects(int curNum);
    void drawText();
    void drawGraphic();
  public:
    Game();
    void start(int startLevel=0); //start game
    void restart(); //restart game
    void end(int winner=0); //end game

    void draw(int multiplier=1);

    void displayOnlyText(bool t); 
    void setDefaultFile1(std::string file);
    void setDefaultFile2(std::string file);
    void setSeed(int seed);


};


#endif
