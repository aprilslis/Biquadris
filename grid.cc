#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid(string filename, int startlevel): 
width{11}
,height{18}
,id{1}
,blocksPlaced{0}
,unclearedRows{0}
,levelNum{startlevel}
,seed{0}
,defaultFile{filename}
,startLevel{startlevel}
,cur{nullptr}
,next{nullptr}
,level{nullptr}
,s{nullptr}
{
    for (int i = 0; i < height; i++) {
        vector <Cell *> temp;
        for (int j = 0 ; j < width; j++) {
            temp.push_back(new Cell{i,j});
        }
        board.push_back(temp);
    }

    s = new Score();
    setLevelNum(startLevel);
    cur = level->generateRandomBlock(id, seed);
    updateIds(cur);
    next = level->generateRandomBlock(id, seed);
    
}

Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete board[i][j];
        }
    }
    clearAllPastBlocks();
    delete s;
    delete level;
    delete cur;
    delete next;
}



void Grid::removeIds(int row) {
	for (int i = 0; i < (int)ids.size(); i++) {
		for (int j = 0; j < width; j++) {
			if (ids[i] == board[row][j]->getIdentity()) {
				ncells[i]--;
				if (ncells[i] == 0) {
					int amount = (levels[i] + 1) * (levels[i] + 1);
					s->updateScore(amount);
					ids.erase(ids.begin() + i);
					levels.erase(levels.begin() + i);
					ncells.erase(ncells.begin() + i);
				}
			}
		}
	}
}

void Grid::updateIds(Block *b) {
	b->setIdentity(id);
	ids.push_back(id);
	levels.push_back(level->getLevel());
	ncells.push_back(4);
	++id;
}

void Grid::updateStarBlockId(Block *b) {
	b->setIdentity(id);
	ids.push_back(id);
	levels.push_back(level->getLevel());
	ncells.push_back(1);
	++id;
}

void Grid::resetIds() {
	id = 1;
	ids.clear();
	levels.clear();
	ncells.clear();
}

void Grid::clearAllPastBlocks(){
    for (auto i = pastBlocks.begin(); i != pastBlocks.end(); ++i){
        delete *i;
    }
    pastBlocks.clear();
}



int Grid::getWidth(){
    return width;
}

int Grid::getHeight(){ 
    return height;
}



Cell * Grid::getCell(int row, int col) {
    return board[row][col];
}

void Grid::addBlock() { 
	cur->init(board); 
	++blocksPlaced;
	if (level->getLevel() == 4) {
		if ((blocksPlaced - 1) % 5 == 0 && unclearedRows > 0) {
		 	StarBlock *tempcur = new StarBlock{levelNum,id};
			updateStarBlockId(tempcur);
		 	tempcur->init(board);
		 	tempcur->drop();
		 	delete tempcur;
		}
	}
}

void Grid::replaceBlock(char c) {
    Block *tmp = cur;
    switch (c){
	    case 'i':
            cur = new IBlock{level->getLevel(),id};
            break;
        case 'j':
            cur = new JBlock{level->getLevel(),id};
            break;
        case 'l':
            cur = new LBlock{level->getLevel(),id};
            break;
        case 'o':
            cur = new OBlock{level->getLevel(),id};
            break;
        case 's':
            cur = new SBlock{level->getLevel(),id};
            break;
        case 't':
            cur = new TBlock{level->getLevel(),id};
            break;
        case 'z':
            cur = new ZBlock{level->getLevel(),id};
            break;
        
        default:
            break;
    }
    tmp->emptyBlock();
    cur->init(board);
    delete tmp;
}



string Grid::hint() {
	int maxcur = countFullRows();
	int maxright = maxcur;
	int maxleft = maxcur;
	int times = 0;
	try {
		while (true) {
			moveBlockRight();
			int count = countFullRows();
			if (count > maxright) {
				maxright = count;
			}
			++times;
		}
	} catch (InvalidMoveException &e) {
		for (int i = 0; i < times; i++) {
			moveBlockLeft();
		}
	
	}
	times = 0;
       	try {
            while (true) {
                moveBlockLeft();
                int count = countFullRows();
                if (count > maxleft) {
                    maxleft = count;
                }
                ++times;
            }
        } catch (InvalidMoveException &e) {
            for (int i = 0; i < times; i++) {
                moveBlockRight();
            }
        }
	if (maxright > maxleft) {
		return "Try moving rightwards";
	} 
    else if (maxright < maxleft) {
		return "Try moving leftwards";
	} 
    else if (maxleft > maxcur && maxleft == maxright) {
		return "Try moving leftwards or rightwards";
	} 
    else {
		return "No rows can be cleared right now";
	}
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

void Grid::clearFullRows() {
    for (int i = height-1; i >= 3; i--) {
        if (isFullRow(i)) {
            removeIds(i);
            updateRows(i);
            break;
        }
    }
}

void Grid::updateRows(int row) {
    for (int i = row; i >= 4; i--) {
        for (int j = 0; j < width; j++) {
            board[i][j]->copyCell(board[i - 1][j]);
        }
    }
    for (int k = 0; k < width; k++) {
            board[3][k]->clearCell();
    }
    clearFullRows(); // after we clear one row we check again if the updated grid has any more such full rows
}



void Grid::updateScore() {
	int count = countFullRows();
	int amount = (level->getLevel() + count) * (level->getLevel() + count);
    s->updateScore(amount);

    if (count > 0) {
        unclearedRows = 0;
    } 
    else {
        ++unclearedRows;
    }
    clearFullRows();
}

int Grid::getScore() {
	return s->getScore();
}

int Grid::getHighScore() {
	return s->getHighScore();
}



void Grid::levelUp() { 
    if(levelNum<4) levelNum++;
    Level *tmp = level;
    setLevel();
    delete tmp;

    cur->setLevel(levelNum);
    next->setLevel(levelNum);
} 

void Grid::levelDown() {
    if(levelNum>0) levelNum--;
    Level *tmp = level;
    setLevel();
    delete tmp;

    cur->setLevel(levelNum);
    next->setLevel(levelNum);
}

void Grid::setLevel() {
    switch (levelNum){
        case 0:
            level = new Level0{};
	        level->init(defaultFile);
            break;
        case 1:
            level = new Level1{};
            level->init(defaultFile);
            break;
        case 2:
            level = new Level2{};
            level->init(defaultFile);
            break;
        case 3:
            level = new Level3{};
            level->init(defaultFile);
            break;
        case 4:
            level = new Level4{};
            level->init(defaultFile);
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

int Grid::getLevelNum(){
    return levelNum;
}



void Grid::clearGrid() { 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j]->clearCell(); // resets each cell
        }
    }

    setLevelNum(startLevel);
    levelNum = startLevel;
    resetIds();
    s->resetScore();
    pastBlocks.push_back(cur);
    pastBlocks.push_back(next);
    cur = level->generateRandomBlock(id, seed);
    updateIds(cur);
    next = level->generateRandomBlock(id, seed);

    blocksPlaced = 0;
    unclearedRows = 0;

    clearAllPastBlocks();
    
}

void Grid::printGrid() {
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

string Grid::printRow(int n){
    string output="";
    for(int i=0;i<width;i++){
        if(board[n][i]->getType()=='\0'){
            output = output + " ";
        }
        else{
            output = output + board[n][i]->getType();
        }
        
    }
    return output;
}



void Grid::setSeed(int seed){
    this->seed = seed;
}

void Grid::generateBlock(){
    pastBlocks.push_back(cur);
    cur = next;
    updateIds(cur);
    next = level->generateRandomBlock(id, seed);
}

void Grid::setDefaultFile(string file){
    defaultFile = file;
}

void Grid::changeFile(string file){
    level->init(file);
}

void Grid::isRandom(bool t){
    if(t){
        level->setRandom();
    }
    else{
        level->setNoRandom();
    }
}



void Grid::moveBlockRight(){
    cur->moveRight();
}

void Grid::moveBlockLeft(){
    cur->moveLeft();
}

void Grid::moveBlockDown(){
   	cur->moveDown();
    cur->moveHeavy();
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

void Grid::setHeavy(){
    cur->setHeavy();
}

void Grid::moveHeavy(){
    cur->moveHeavy();
}

Block * Grid::getNextBlock(){
    return next;
}
