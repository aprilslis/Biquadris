#include "grid.h"

using namespace std;

Grid::Grid() : width{11}, height{18}, levelNum{0}, seed{0}, inc{1} { // initialises board
    for (int i = 0; i < height; i++) {
        vector <Cell *> temp;
        for (int j = 0 ; j < width; j++) {
            temp.push_back(new Cell{i,j});
        }
        board.push_back(temp);
    }

    level = new Level0{};
    cur = level->generateRandomBlock(seed);
    cur->setIdentity(inc);
    ids.push_back(inc);
    levels.push_back(level->getLevel());
    ncells.push_back(4);
    ++inc;
    next = level->generateRandomBlock(seed);
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

void Grid::removeIds(int row) {
	for (int i = 0; i < (int)ids.size(); i++) {
		for (int j = 0; j < width; j++) {
			if (ids[i] == board[i][j]->getIdentity()) {
				--ncells[i];
				if (ncells[i] == 0) {
					// increase score 
					ids.erase(ids.begin() + i);
					levels.erase(levels.begin() + i);
					ncells.erase(ncells.begin() + i);
				}
			}
		}
	}
}

void Grid::addBlock() { //add a new block at left top corner
    cur->init(board); 
}

void Grid::replaceBlock(char c) { // replace current block with new block I,J,L
    Block *tmp = cur;
    switch (c){
        case 'i':
            cur = new IBlock{};
            break;
        case 'j':
            cur = new JBlock{};
            break;
        case 'l':
            cur = new LBlock{};
            break;
        
        default:
            break;
    }
    tmp->emptyBlock();
    cur->init(board);
    delete tmp;
}

bool Grid::isFullRow(int row) {
    for (int j = 0; j < width; j++) {
        if (board[row][j]->getType() == '\0') {
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
    if(levelNum<4) levelNum++;
    Level *tmp = level;
    setLevel();
    delete tmp;

    //add score sstuff
    //score.setScore(levelNum);
} 

void Grid::levelDown() {
    if(levelNum>0) levelNum--;
    Level *tmp = level;
    delete tmp;

    //add score sstuff
    //score.setScore(levelNum);
}

void Grid::setLevel() {
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
        case 3:
            level = new Level3{};
            break;
        case 4:
            level = new Level4{};
            break;
        
        default:
            break;
    }
}

void Grid::setLevelNum(int n){
    levelNum = n;
    Level *tmp = level;
    setLevel();
    delete tmp;
}

void Grid::clearGrid() { 
    for (int i = 3; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j]->clearCell(); // resets each cell
        }
    }
    Level *tmp = level;
    level = new Level0{};
    delete tmp;

    levelNum = 0;
    //need to reset sequence too
    cur = level->generateRandomBlock(seed);
    next = level->generateRandomBlock(seed);
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




void Grid::setSeed(int seed){
    this->seed = seed;
}

void Grid::generateBlock(){
    cur = next;
    cur->setIdentity(inc);
    ids.push_back(inc);
    levels.push_back(level->getLevel());
    ncells.push_back(4);
    inc++;
    next = level->generateRandomBlock(seed);
}

void Grid::moveBlockRight(){
    cur->moveRight();
}

void Grid::moveBlockLeft(){
    cur->moveLeft();
}

void Grid::moveBlockDown(){
    cur->moveDown();
}

void Grid::dropBlock(){
    cur->drop();
}

void Grid::rotateBlockCW(){
    cur->rotateCW();
}

void Grid::rotateBlockCCW(){
    cur->rotateCCW();
}

