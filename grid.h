#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <vector>
#include "block.h"
#include "cell.h"

using namespace std;

class Grid{
    const int width; //grid width
    const int height; //grid height
    vector<vector<Cell *>> board; //game board: row/height<column/width<cell>>
    Block *cur; //current block we are working with

    int level = 0; //current level
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
    
    
};

#endif
