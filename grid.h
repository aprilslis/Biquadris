#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include "cell.h"
#include "block.h"
using namespace std;

class Grid{
    const int width = 11; //grid width
    const int height = 18; //grid height
    vector<vector<Cell *>> board; //game board: column/width<row/height<cell>>
    Block *cur; //current block we are working with

    int level=0; //current level
    int some_special_effects; //(add later)

  public:
    void printGrid(); //print out current board
    void init(); //start a new game
    bool won(); //check if game has ended
    void clearBoard(); //release all existing cells
    Cell *getCell(int x, int y); //get cell at x,y
    void setCell(Cell *c, int x, int y); //set cell at x,y
    
    void clearRow(int y); //clear row at x
    int findCompleteRows(); //check for completed rows, return number of rows cleared
    void updateBoard(int y); //used after clearing row/block, let all block fall over gravity(?)

    void addBlock(Block *b); //add a new given block at left top corner
    void replaceBlock(Block *b); //replace current block with new block b

    void levelUp(); //level game up
    void levelDown(); //level game down

};



#endif
