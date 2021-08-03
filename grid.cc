#include <vector>
#include <iostream>
#include "cell.h"
#include "grid.h"
using namespace std;


void Grid::printGrid(){
    cout<<"printing gird:-------------------------"<<endl;
    for(int i=0;i<width;i++){
        for(int j=0;i<height;i++){
            cout<<board[i][j]->getType()<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------------------------"<<endl;
} //print out current board


void Grid::newGame(){
    for(int i=0;i<width;i++){
        board.emplace_back();
        for(int j=0;i<height;i++){
            board[i].emplace_back(new Cell{i,j});
        }
    }
} //start a new game


bool Grid::endGame(){
    
} //check if game has ended


void Grid::clearBoard(){
    for(int i=0;i<width;i++){
        for(int j=0;i<height;i++){
            delete board[i][j];
        }
    }
} //release all existing cells


Cell * Grid::getCell(int x, int y){
    return board[x][y];
} //get cell at x,y


void Grid::setCell(Cell *c, int x, int y){
    Cell *temp = board[x][y];
    board[x][y] = c;
    delete temp;
} //set cell at x,y


void Grid::clearRow(int y){
    for(int i=0;i<width;i++){
        setCell(nullptr,i,y);
    }
} //clear row at x


int Grid::findCompleteRows(){
    int rowsCleared=0;
    for(int j=0;j<height;j++){
        int count = 0;
        for(int i=0;i<width;i++){
            if(board[i][j]->getType()!='\0') count++;
        }
        if(count==width){
            rowsCleared++;
            clearRow(j);
            updateBoard(j);
        }
    }

    return rowsCleared;
} //check for completed rows, return number of rows cleared


void Grid::updateBoard(int y){
    for(int i=0;i<width;i++){
        for(int j=y-1;j>0;j--){
            board[i][j+1] = board[i][j];
        }
    }

    for(int i=0;i<width;i++){
        board[i][0] = new Cell{i,0};
    }

} //used after clearing row/block, let all block fall over gravity(?)


void Grid::addBlock(Block *b){
    b->init(board); //needs to change block class
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

