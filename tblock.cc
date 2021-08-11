#include "tblock.h"

using namespace std;

TBlock::TBlock(int level): Block{level} {}

// void TBlock::moveHeavy() {
// 	if (level == 4 || level == 3) {
// 		moveDown();
// 	}
// }

char TBlock::getType() {
	return 'T';
}

void TBlock::switchBlocks(vector<Cell *> other) {
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
	                block[j]->setType('T');
			block[j]->setIdentity(identity);
	         }
	         throw InvalidMoveException();
	    }
	} 

	//doing the switch 
	block.clear();
	block = other;
	for (int i = 0; i < size; i++) {
	        block[i]->setType('T'); 
		block[i]->setIdentity(identity);
	}
	lowerleft = other[0];
}

void TBlock::init(std::vector<std::vector<Cell *>> &g) {
	grid = g;
	pos = 1;
	size = 4;
	lost();
	lowerleft = grid[3][1];
	block.push_back(lowerleft);
	block.push_back(grid[2][0]);
	block.push_back(grid[2][1]);
	block.push_back(grid[2][2]);
	for (int i = 0; i < size; i++) {
		block[i]->setType('T');
		block[i]->setIdentity(identity);
	}
}



void TBlock::lost() {
	if (grid[3][1]->isFull() || grid[2][0]->isFull() || grid[2][1]->isFull() || grid[2][2]->isFull()) {
		throw LostException();
	}
}

void TBlock::moveLeft() {
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

void TBlock::moveRight() {
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

// void TBlock::moveHeavyDown() {
// 	moveDown();
// 	moveDown();
// }

void TBlock::moveDown() {
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

void TBlock::drop() {
	try {
		while(true) {
			moveDown();
		}
	} catch (InvalidMoveException &e) {
	}
}

void TBlock::rotateCW() {
	vector<Cell *> temp;
	int row = lowerleft->getRow();
	int col = lowerleft->getCol();
	if (pos == 1) {
		if (row - 1 < 0 || row - 2 < 0 || col - 1 > 0) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col - 1]);
		temp.push_back(grid[row - 2][col]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 2) {
		if (row - 1 < 0 || col + 1 > 10 || col - 1 < 0) {
			throw InvalidMoveException();
		}
        	temp.push_back(lowerleft);
		temp.push_back(grid[row][col - 1]);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row - 1][col]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 3) {
		if (row - 1 < 0 || row - 2  < 0 || col + 1 > 10) {
			throw InvalidMoveException();
		}
        	temp.push_back(lowerleft);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 2][col]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 4) {
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException ();
		}
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 1][col + 2]);	
		switchBlocks(temp);
		pos = 1;
	}
	moveHeavy();
}

void TBlock::rotateCCW() {
	vector<Cell *> temp;
	int row = lowerleft->getRow();
	int col = lowerleft->getCol();
	if (pos == 1) {
		if (row - 1 < 0 || col - 1 < 0 || row - 2 < 0) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col - 1]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col - 1]);
		temp.push_back(grid[row - 2][col - 1]);
		switchBlocks(temp);
		pos = 4;
	} else if (pos == 4) {
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException();
		}
        	temp.push_back(lowerleft);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row - 1][col + 1]);
		switchBlocks(temp);
		--pos;
	} else if (pos == 3) {
		if (row - 1 < 0 || row - 2 < 0 || col + 1 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 2][col + 1]);
		switchBlocks(temp);
		--pos;
	} else if (pos == 2) {
		if (row - 1 < 0 || col + 1 > 10 || col - 1 < 0) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col - 1]);
		temp.push_back(grid[row - 1][col + 1]);
		switchBlocks(temp);
		--pos;
	}
	moveHeavy();
}
