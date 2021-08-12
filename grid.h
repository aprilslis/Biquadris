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
    const int width; //grid width
    const int height; //grid height
    int id; // generates ids
    
    int blocksPlaced;
    int unclearedRows;

    std::vector<std::vector<Cell *>> board; //game board: row/height<column/width<cell>>

    int levelNum;
    Level *level; //current level
    int seed;
    std::string defaultFile;


    Block *cur;
    Block *next;

    Score *s; //score member to track score

    std::vector<int> ids; // stores all ids different blocks have
    std::vector<int> levels; // stores levels corresponding to the ids
    std::vector<int> ncells;  // stores no of left cells in a block if an id
    std::vector<Block *> pastBlocks; //stores pointers to the past blocks so we can free them later

    void removeIds(int row); // removes id if cleared row removes last cell of a certain block
    void updateIds(Block *b);
    void resetIds();
    void clearAllPastBlocks(); //free all past block pointers

  public:
    Grid(std::string filename);
    ~Grid();

    int getWidth(); //return width of grid
    int getHeight(); //return height of grid
    
    Cell *getCell(int x, int y); // get cell at (row, column)  
    void addBlock(); // add a new block at left top corner
    void replaceBlock(char c); // replace current block with new block I,J,L
    
    void updateScore();

    std::string hint();

    bool isFullRow(int row); // checks if row is full
    int countFullRows(); // returns number of full rows
    void clearFullRows(); // clears the full rows one at a time
    void updateRows(int y); // used after clearing row/block, let all block fall over gravity(?)

    int getScore();
    int getHighScore();

    void levelUp(); // level game up
    void levelDown(); // level game down
    void setLevel(); //update the level
    void setLevelNum(int n); //set the levelNum to be n
    int getLevelNum(); //get levelNum
    
    void clearGrid(); // resets the grid
    void printGrid(); // print out current board (for testing)
    std::string printRow(int n); // print out current board

    void setSeed(int seed);
    void generateBlock();//generate a random block 
    void setDefaultFile(std::string file); //set the name of default file
    void changeFile(std::string file); //change the file input block to the new one
    void isRandom(bool t); //set board to generate random block or not

    void moveBlockRight();
    void moveBlockLeft();
    void moveBlockDown();
    void dropBlock();
    void rotateBlockCW();
    void rotateBlockCCW();
    Block *getNextBlock();

    void setHeavy(); //this handles the special effect Heavy
    void moveHeavy();
};

#endif
