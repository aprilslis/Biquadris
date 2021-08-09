#include "sblock.h"

using namespace std;

SBlock::SBlock(int level): Block{level} {}

void SBlock::moveHeavy() {
        if (this->isHeavy == true) {
                moveDown();
        }
}

char SBlock::getType() {
	return 'S';
}

void SBlock::switchBlocks(vector<Cell *> other) {
	// emptying block temporarily
	for (int i = 0; i < size; i++) { 
	        block[i]->setType('\0'); 
		block[i]->setIdentity(0);
	}

	// asserting invariants
	for (int i = 0; i < size; i++) {
	    if (other[i]->isFull()) {
	    	// rewinding block
	        for (int j = 0; j < size; j++) {
	                block[j]->setType('S');
			block[j]->setIdentity(identity);
	         }
	         throw InvalidMoveException();
	    }
	} 

	//doing the switch 
	block.clear();
	block = other;
	for (int i = 0; i < size; i++) {
	        block[i]->setType('S'); 
		block[i]->setIdentity(identity);
	}
	lowerleft = other[0];
}

void SBlock::init(std::vector<std::vector<Cell *>> &g) {
	grid = g;
	pos = 1;
	size = 4;
	lost();
	lowerleft = grid[3][0];
	block.push_back(lowerleft);
	block.push_back(grid[3][1]);
	block.push_back(grid[2][1]);
	block.push_back(grid[2][2]);
	for (int i = 0; i < size; i++) {
		block[i]->setType('S');
		block[i]->setIdentity(identity);
	}
}



void SBlock::lost() {
	if (grid[3][0]->isFull() || grid[3][1]->isFull() || grid[2][1]->isFull() || grid[2][2]->isFull()) {
		throw LostException();
	}
}

void SBlock::moveLeft() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() - 1 < 0) {
			throw InvalidMoveException();
		}
	}

	vector<Cell *> temp;
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col - 1]);
	}

	switchBlocks(temp);
	moveHeavy();
}

void SBlock::moveRight() {					// opposite of moving left
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() + 1 > 10) {
			throw InvalidMoveException();
		}
	}

	vector<Cell *> temp;
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col + 1]);
	}

	switchBlocks(temp);
	moveHeavy();
}

void SBlock::moveHeavyDown() {
	moveDown();
	moveDown();
}

void SBlock::moveDown() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getRow() + 1 > 17) {
			throw InvalidMoveException(); 
		}
	}

	vector<Cell *> temp;
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row + 1][col]);
	}

	switchBlocks(temp);
}

void SBlock::drop() {
	try {
		while(true) {
			moveDown();
		}
	} catch (InvalidMoveException &e) {
	}
}

void SBlock::rotateCW() {
	vector<Cell *> temp;
	int row = lowerleft->getRow();
	int col = lowerleft->getCol();
	if (pos == 1) {
		if (row - 1 < 0 || row - 2 < 0 || col + 1 > 10) {
			throw InvalidMoveException();
		}
        	temp.push_back(grid[row][col + 1]);
        	temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col+1]);
        	temp.push_back(grid[row - 2][col]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 2) {
		if (row - 1 < 0 || col + 1 > 10 || col - 1 < 0) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row][col - 1]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		switchBlocks(temp);
	    --pos;
	}
	moveHeavy();
}

void SBlock::rotateCCW() {  // CCW and CW have same effect as there are 2 positions in SBlock
	rotateCW();
}

