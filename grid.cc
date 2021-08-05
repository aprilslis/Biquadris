#include "grid.h"

using namespace std;

Grid::Grid() : width{11}, height{18}, cur{nullptr}, levelNum{0} { // initialises board
    for (int i = 0; i < height; i++) {
        vector <Cell *> temp;
        for (int j = 0 ; j < width; j++) {
            temp.push_back(new Cell{i,j});
        }
        board.push_back(temp);
    }

    level = new Level0{};
}

Grid::~Grid() { // release all existing cells
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete board[i][j];
        }
    }
    delete level;
}

Cell * Grid::getCell(int row, int col) {
    return board[row][col];
} //get cell at x,y

void Grid::addBlock(Block *b) { //add a new given block at left top corner
    b->init(board); //needs to change block class
    cur = b;
}

void Grid::replaceBlock(Block *b) { // replace current block with new block b
    cur->emptyBlock();
    addBlock(b);
}

bool Grid::isFullRow(int row) {
    cout<<"here"<<endl;
    for (int j = 0; j < width; j++) {
        if (board[row][j]->getType() == '\0') {
            return false;
        }
    }
    cout<<"returned true"<<endl;
    return true;
}

int Grid::countFullRows() {
    cout<<"hereee"<<endl;
    int count = 0;
    for (int i = 3; i < height; i++) {
        if (isFullRow(i)) {
            count++;
        }
    } 
    return count;
}

void Grid::clearFullRows() { // check for completed rows, return number of rows cleared
    for (int i = height-1; i >= 3; i--) {
        if (isFullRow(i)) {
            updateRows(i);
            break;
        }
    }
}

void Grid::updateRows(int row) { // each row moves down and top row gets cleared
    for (int i = row; i >= 4; i--) {
        for (int j = 0; j < width; j++) {
            board[i][j]->copyCell(board[i - 1][j]);
            //board[i][j] = board[i - 1][j];
        }
    }
    for (int k = 0; k < width; k++) {
            board[3][k]->clearCell();
    }
    clearFullRows(); // after we clear one row we check again if the updated grid has any more such full rows
}

void Grid::levelUp() { 
<<<<<<< HEAD
    if(levelNum<5) levelNum++;
    Level *tmp = level;
    switch (levelNum){
        case 0:
            level = new Level0{};
            break;
        case 1:
            level = new Level1{};
            break;
        case 2:
            level = new Level2{};
            break;
        // case 3:
        //     level = new Level3{};
        //     break;
        // case 4:
        //     level = new Level4{};
        //     break;
        
        default:
            break;
    }
    delete tmp;
} 

void Grid::levelDown() {
    if(levelNum>=0) levelNum--;
=======
    ++level;
    // add score stuff
    //score.setScore(level);
} 

void Grid::levelDown() {
    --level;
    // add score stuff
    //score.setScore(level);
>>>>>>> d5766c800cad9e44eb2a77fa96ba3fed8dbfe775
}

void Grid::clearGrid() { 
    for (int i = 3; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j]->clearCell(); // resets each cell
        }
    }
}
void Grid::printGrid() { // prints out current board
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(board[i][j]->getType()=='\0'){
                cout << "." << " ";
            }
            else{
                cout << board[i][j]->getType() << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}




Block * Grid::generateBlock(){
    if(level==0){

    }
}

void moveBlockRight(Block *b);
void moveBlockLeft(Block *b);
void moveBlockDown(Block *b);
void dropBlock(Block *b);
void rotateBlockCW(Block *b);
void rotateBlockCCW(Block *b);
void setFilename(string newfile);

