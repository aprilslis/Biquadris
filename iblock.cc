#include "iblock.h"

using namespace std;

void switchBlocks(vector<Cell *> other) {
	// emptying block temporarily
	for (int i = 0; i < size; i++) { 
	        block[i]->setType('\0'); 
	}

	// asserting invariants
	for (int i = 0; i < size; i++) {
	    if (other[i]->isFull()) {
	    	// rewinding block
	        for (int j = 0; j < size; j++) {
	                block[j]->setType('I');
	         }
	         throw InvalidMoveException e{};
	    }
	} 

	//doing the switch 
	block.clear();
	block = other;
	for (int i = 0; i < size; i++) {
	        block[i]->setType('I'); 
	}
	lowerleft = other[0];
}

void IBlock::init(vector<vector<Cell *>> g) {
	grid = g;
	pos = 1;
	size = 4;
	lost();
	lowerleft = grid[3][0];
	block.push_back(lowerleft);
	block.push_back(grid[3][1]);
	block.push_back(grid[3][2]);
	block.push_back(grid[3][3]);
	for (int i = 0; i < size; i++) {
		block[i]->setType('I');
	}
}

bool IBlock::lost() {
	if (grid[3][0]->isFull() || grid[3][1]->isFull() || grid[3][2]->isFull() || grid[3][3]->isFull()) {
		throw LostException();
	}
}

void IBlock::moveLeft() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() - 1 < 0) {
			throw InvalidMoveException e{};
		}
	}

	vector<Cell *> temp;
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col - 1]);
	}

	switchBlocks(temp);
}

void IBlock::moveRight() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() + 1 > 10) {
			throw InvalidMoveException e{};
		}
	}

	vector<Cell *> temp;
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col + 1]);
	}

	switchBlocks(temp);
}

void IBlock::moveDown() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getRow() + 1 > 17) {
			throw InvalidMoveException e{}; 
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

void IBlock::drop() {
	try {
		while(true) {
			moveDown();
		}
	}
}

void IBlock::rotationCW() {
    vector<Cell *> temp;
    int row = lowerleft->getRow;
	int col = lowerleft->getCol;
	if (pos == 1) {
		if (row - 1 < 0 || row - 2 < 0 || row - 3 < 0) {
			throw InvalidMoveException e{};
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 2][col]);
		temp.push_back(grid[row - 3][col]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 2) {
		if (col + 1 < 10 || col + 2 < 10 || col + 3 < 10) {
			throw InvalidMoveException e{};
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row][col + 3]);
		switchBlocks(temp);
		--pos;
	}

}

void IBlock::rotationCCW() { // CCW and CW have same effect as there are 2 positions in IBlock 
	rotationCW();
}
