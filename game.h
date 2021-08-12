#ifndef _GAME_H_
#define _GAME_H_

#include "grid.h"
#include "basedisplay.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Game{

    std::string fileCmds;
    bool useSeqFile;

    Grid board1;
    Grid board2;

    bool onlyText;
    TextDisplay textdisplay;
    GraphicDisplay graphicdisplay;

    void specialEffects(int curNum);
    void drawText();
    void drawGraphic();
  public:
    Game();
    void start(int startlevel=0); //start game
    void restart(int startlevel=0); //restart game
    void end(int winner=0); //end game

    void draw(int multiplier=1);

    void displayOnlyText(bool t); 
    void setDefaultFile1(std::string file);
    void setDefaultFile2(std::string file);
    void setSeed(int seed);

};

class InvalidCommand{};//raised when command is invalid
class CannotOpenFile{};//raised when the input file cant be found/opened

#endif
