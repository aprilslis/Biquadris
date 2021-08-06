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
#include "score.h"

class Grid{
    const int width; //grid width
    const int height; //grid height
    int id; // generates ids

    vector<vector<Cell *>> board; //game board: row/height<column/width<cell>>

    int levelNum;
    Level *level; //current level
    int seed;

    Block *cur;
    Block *next;

    Score *s; //score member to track score

    vector<int> ids; // stores all ids different blocks have
    vector<int> levels; // stores levels corresponding to the ids
    vector<int> ncells;  // stores no of left cells in a block if an id

    void removeIds(int row); // removes id if cleared row removes last cell of a certain block
    void updateIds(Block *b);
    void resetIds();

  public:
    Grid();
    ~Grid();
    
    Cell *getCell(int x, int y); // get cell at (row, column)  
    void addBlock(); // add a new block at left top corner
    void replaceBlock(char c); // replace current block with new block I,J,L
    
    bool isFullRow(int row); // checks if row is full
    int countFullRows(); // returns number of full rows
    void clearFullRows(); // clears the full rows one at a time
    void updateRows(int y); // used after clearing row/block, let all block fall over gravity(?)

    void setScore(Score *s);

    void levelUp(); // level game up
    void levelDown(); // level game down
    void setLevel(); //update the level
    void setLevelNum(int n); //set the levelNum to be n
    
    void clearGrid(); // resets the grid
    void printGrid(); // print out current board


    void setSeed(int seed);
    void generateBlock();//generate a random block 
    void moveBlockRight();
    void moveBlockLeft();
    void moveBlockDown();
    void dropBlock();
    void rotateBlockCW();
    void rotateBlockCCW();
    //void setFilename(string newfile);

    
    
};

#endif
