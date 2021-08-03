#include <vector>
#include <iostream>
#include "cell.h"
#include "grid.h"

using namespace std;

void Grid::printGrid(){
    cout << endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << grid[i][j]->getType() << " ";
        }
        cout << endl;
    }
    cout << endl;
} //print out current board


void Grid::init() { // initialises the board
    for(int i = 0; i < height; i++){
        //board.emplace_back();
        vector <Cell *> temp;
        for(int j = 0 ; j < width; j++){
            temp.push_back(new Cell{i,j});
        }
        grid.push_back(temp);
    }
} //start a new game


bool Grid::won() {
    
} //check if game has ended


void Grid::clearGrid() {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            delete grid[i][j];
        }
        grid[i].clear();
    }
} //release all existing cells


Cell * Grid::getCell(int row, int col) {
    return grid[row][col];
} //get cell at x,y


void Grid::clearFullRows(){
    for (int i = height; i >= 3; i--) {
        int count = 0;
        char c = grid[i][0]->getType();
        for (int j = 1; j < width; j++) {
            if (board[i][j]->getType() == c) {
                count++;
            }
        }
        if (count == width) { 
            updateRows(i);
            return;
        }
    }
} // check for completed rows, return number of rows cleared


void Grid::updateRows(int row){
    if (i == 3) {
        for (int j = 0; j < width; j++) {
            grid[i][j]->clearCell();
        }
    } else {
        for (int i = row; i >= 3; i--) {
            for (int j = 0; j < width; j++) {
                grid[i][j] = grid[i - 1][j];
            }
        }
    }
    clearFullRows(); // after we clear one row we check again if the updated grid has any more such full rows
} // used after clearing row/block, let all block fall over gravity(?)


void Grid::addBlock(Block *b){
    b->init(grid); //needs to change block class
    cur = b;
} //add a new given block at left top corner


void Grid::replaceBlock(Block *b){
    cur->emptyBlock();
    addBlock(b);
} //replace current block with new block b



void Grid::levelUp(){
    
} //level game up


void Grid::levelDown(){

} //level game down

