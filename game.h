#ifndef _GAME_H_
#define _GAME_H_

#include "grid.h"
#include "basedisplay.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Game{

    std::string fileCmds; //this is for the commannd "sequence file", this would store the content of input file
    bool useSeqFile;      //if current game is using the file input, fileCmds

    Grid board1; //player 1's game board
    Grid board2; //player 2's game board

    bool onlyText;                 //if game only displays text (no graphic display)
    TextDisplay textdisplay;       //text display of game
    GraphicDisplay graphicdisplay; //graphic display of game

    void specialEffects(int curNum); //handle special actions of player when cleared more than 1 row
    void drawText();                 //show text display of current game
    void drawGraphic();              //show graphic display current game

public:
    Game(std::string file1, std::string file2, int startlevel); //constructor
    std::string getInput();                                     //get next file input
    void start();                                               //start game
    void restart();                                             //restart game
    void end(int winner = 0);                                   //end game

    void draw(int multiplier = 1); //show display of game

    void displayOnlyText(bool t); //set value of field onlyText
    void setSeed(int seed);       //set seed of game
};

class InvalidCommand{}; //raised when command is invalid
class CannotOpenFile{}; //raised when the input file cant be found/opened

#endif
