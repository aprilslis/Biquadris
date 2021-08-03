#include <vector>
#include <iostream>
#include "cell.h"
#include "grid.h"

using namespace std;

void Grid::Grid() : width{11}, height{18}, cur{nullptr} {}

void Grid::printGrid(){
    cout << endl;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << board[i][j]->getType() << " ";
        }
        cout << endl;
    }
    cout << endl;
} //print out current board


void Grid::init() { // initialises the board
    for(int i = 0; i < height; i++) {
        vector <Cell *> temp;
        for(int j = 0 ; j < width; j++) {
            temp.push_back(new Cell{i,j});
        }
        board.push_back(temp);
    }
}


bool Grid::won() {
    
}


void Grid::clearBoard() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete board[i][j];
        }
    }
} //release all existing cells


Cell * Grid::getCell(int row, int col) {
    return board[row][col];
} //get cell at x,y

bool Grid::isFullRow(int row) {
    char c = board[row][0];
    if (c == '\0') {
        return false;
    }
    for (int j = 1; j < width; j++) {
        if (grid[row][j]->getType() ! = c) {
            return false;
        }
    }
    return true;
}

int Grid::countFullRows() {
    int count = 0;
    for (int i = 3; i < height; i++) {
        if (isFullRow(i)) {
            count++;
        }
    } 
    return count;
}

void Grid::clearFullRows() {
    for (int i = height; i >= 0; i--) {
        if (isFullRow(i)) {
            updateRows(i);
        }
    }
} // check for completed rows, return number of rows cleared


void Grid::updateRows(int row) { // each row moves down and top row gets cleared
    for (int i = row; i >= 4; i--) {
        for (int j = 0; j < width; j++) {
            board[i][j] = board[i - 1][j];
        }
    }
    for (int k = 0; k < width; k++) {
            board[3][k]->clearCell();
    }
    clearFullRows(); // after we clear one row we check again if the updated grid has any more such full rows
} // used after clearing row/block, let all block fall over gravity(?)


void Grid::addBlock(Block *b) {
    b->init(board); //needs to change block class
    cur = b;
} //add a new given block at left top corner


void Grid::replaceBlock(Block *b) {
    cur->emptyBlock();
    addBlock(b);
} //replace current block with new block b



void Grid::levelUp() {    
} //level game up


void Grid::levelDown(){
} //level game down

