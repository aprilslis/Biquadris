#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <vector>
#include "cell.h"
<<<<<<< HEAD
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
// #include "level3.h"
// #include "level4.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
=======
#include "score.h"

>>>>>>> d5766c800cad9e44eb2a77fa96ba3fed8dbfe775
using namespace std;

class Grid{
    const int width; //grid width
    const int height; //grid height
    vector<vector<Cell *>> board; //game board: row/height<column/width<cell>>
    Block *cur; //current block we are working with

<<<<<<< HEAD
    int levelNum;
    Level *level; //current level

    Block *cur;
    Block *next;
=======
    int level = 0; //current level
    Score score{level}; //score member to track score
>>>>>>> d5766c800cad9e44eb2a77fa96ba3fed8dbfe775
    int some_special_effects; //(add later)

  public:
    Grid();
    ~Grid();
    
    Cell *getCell(int x, int y); // get cell at (row, column)  
    void addBlock(Block *b); // add a new given block at left top corner
    void replaceBlock(Block *b); // replace current block with new block b
    
    bool isFullRow(int row); // checks if row is full
    int countFullRows(); // returns number of full rows
    void clearFullRows(); // clears the full rows one at a time
    void updateRows(int y); // used after clearing row/block, let all block fall over gravity(?)

    void levelUp(); // level game up
    void levelDown(); // level game down
    
    void clearGrid(); // resets the grid
    void printGrid(); // print out current board


    Block *generateBlock();//generate a random block from file if provide
    void moveBlockRight(Block *b);
    void moveBlockLeft(Block *b);
    void moveBlockDown(Block *b);
    void dropBlock(Block *b);
    void rotateBlockCW(Block *b);
    void rotateBlockCCW(Block *b);
    void setFilename(string newfile);

    
    
};

#endif
