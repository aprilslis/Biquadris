#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <vector>
#include "cell.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "starblock.h"
#include "score.h"

class Grid{
    const int width;                        //grid width
    const int height;                       //grid height
    std::vector<std::vector<Cell *>> board; //game board: row/height<column/width<cell>>

    int blocksPlaced;  //number of blocks that have been palced(used for level 4 to check when to drop star block)
    int unclearedRows; //number of uncleared rows

    int levelNum;            //current level number
    Level *level;            //current level
    int seed;                //seed
    std::string defaultFile; //default file input
    int startLevel;          //starting level of each game

    Block *cur;  //current block input
    Block *next; //next block input

    Score *s; //score member to track score

    int id;                          // generates ids
    std::vector<int> ids;            // stores all ids different blocks have
    std::vector<int> levels;         // stores levels corresponding to the ids
    std::vector<int> ncells;         // stores no of left cells in a block if an id
    std::vector<Block *> pastBlocks; //stores pointers to the past blocks so we can free them later

    void removeIds(int row);          // removes id if cleared row removes last cell of a certain block
    void updateIds(Block *b);         //update the ids
    void updateStarBlockId(Block *b); //update id for star
    void resetIds();                  //resets all ids
    void clearAllPastBlocks();        //free all past block pointers

public:
    Grid(std::string filename, int startlevel); //constructor
    ~Grid();                                    //destructor

    int getWidth();  //return width of grid
    int getHeight(); //return height of grid

    Cell *getCell(int x, int y); // get cell at (row, column)
    void addBlock();             // add a new block at left top corner
    void replaceBlock(char c);   // replace current block with new block I,J,L

    std::string hint(); //prduce a hint for player

    bool isFullRow(int row); // checks if row is full
    int countFullRows();     // returns number of full rows
    void clearFullRows();    // clears the full rows one at a time
    void updateRows(int y);  // used after clearing row/block, let all block fall over gravity

    void updateScore(); //update current score of game
    int getScore();     //get current score of game

    void levelUp();          // level game up
    void levelDown();        // level game down
    void setLevel();         //update the level
    void setLevelNum(int n); //set the levelNum to be n
    int getLevelNum();       //get levelNum

    void clearGrid();            // resets the grid
    void printGrid();            // print out current board (for testing)
    std::string printRow(int n); // print out current board

    void setSeed(int seed);                //set the current game's seed to be integer, seed
    void generateBlock();                  //generate a random block
    void setDefaultFile(std::string file); //set the name of default file
    void changeFile(std::string file);     //change the file input block to the new one
    void isRandom(bool t);                 //set board to generate random block or not

    void moveBlockRight(); //move the current block input right on board
    void moveBlockLeft();  //move the current block input left on board
    void moveBlockDown();  //move the current block input down on board
    void dropBlock();      //drop the current block input on board
    void rotateBlockCW();  //rotate the current block input clockwise on board
    void rotateBlockCCW(); //rotate the current block input counterclockwise on board
    void setHeavy();       //this handles the special action Heavy
    void moveHeavy();      //move the block down according to its heaviness

    Block *getNextBlock(); //get thhe pointer of the next block input
};

#endif
