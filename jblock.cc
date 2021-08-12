#include "jblock.h"
using namespace std;

JBlock::JBlock(int level): Block{level} {}

char JBlock::getType(){
	return 'J';
}

// void JBlock::moveHeavy() {
// 	if (level == 4 || level == 3) {
// 		moveDown();
// 	}
// }


void JBlock::switchBlocks(vector<Cell *> other) {
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
	                block[j]->setType('J');
			block[j]->setIdentity(identity);
	         }
	         throw InvalidMoveException();
	    }
	} 

	//doing the switch 
	block.clear();
	block = other;
	for (int i = 0; i < size; i++) {
	        block[i]->setType('J');
		block[i]->setIdentity(identity);
	}
	lowerleft = other[0];
}

void JBlock::init(std::vector<std::vector<Cell *>> &g) {
	grid = g;
	pos = 1;
	size = 4;
	lost(); // checking whether the initial position of the block is empty
	//pushing the initial configuration into our block vector 
	lowerleft = grid[3][0];
	block.push_back(lowerleft);
	block.push_back(grid[3][1]);
	block.push_back(grid[3][2]);
	block.push_back(grid[2][0]);
	for (int i = 0; i < size; i++) {
		block[i]->setType('J'); // setting our block of the empty cells to J type cells
		block[i]->setIdentity(identity);
	}
}



void JBlock::lost() { // checks if the first position of the block is in losing condition (i.e. one or more cells are filled)
	if (grid[3][0]->isFull() || grid[3][1]->isFull() || grid[3][2]->isFull() || grid[2][0]->isFull()) {
		throw LostException();
	}
}

void JBlock::moveLeft() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() - 1 < 0) {  // checking whether each cell is part of grid
			throw InvalidMoveException();
		}
	}

	vector<Cell *> temp; // this will store the block to one left of current block
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col - 1]); // pushing each cell to the left of current cell
	}

	switchBlocks(temp);
}

void JBlock::moveRight() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getCol() + 1 > 10) { // checking whether each cell is part of grid
			throw InvalidMoveException();
		}
	}

	vector<Cell *> temp; // this will store the block to one right of current block
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row][col + 1]); // pushing each cell to the right of current cell
	}

	switchBlocks(temp);
}


void JBlock::moveDown() {
	for (int i = 0; i < size; i++) {
		if (block[i]->getRow() + 1 > 17) { // checking whether each cell is part of grid
			throw InvalidMoveException(); 
		}
	}

	vector<Cell *> temp; // this will store the block to one right of current block
	for (int i = 0; i < size; i++) {
		int row = block[i]->getRow();
		int col = block[i]->getCol();
		temp.push_back(grid[row + 1][col]); // pushing each below the current cell 
	}

	switchBlocks(temp);
}

void JBlock::drop() {
	try {
		while(true) {
			moveDown(); // keeps moving down as long as it is valid
		}
	} catch (InvalidMoveException &e) {
	}
}

//
// -> clockwise
// POS = 1	POS = 2		POS = 3		POS = 4
//	        JJ				 J	
// J            J		JJJ		 J
// JJJ          J		  J		JJ	
// <- anticlockwise
//Notes:
//1)In position three the lowerleft is the lowest block
//2)Make use of the diagrams to write code for rotation
//3)Remember to change positions use the lowerleft cell of initial position always 
//

void JBlock::rotateCW() {
	vector<Cell *> temp;
	int row = lowerleft->getRow();
	int col = lowerleft->getCol();
	if (pos == 1) { // pos 1 -> pos 2
		if (row - 1 < 0 || row - 2 < 0 || col + 1 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 2][col]);
		temp.push_back(grid[row - 2][col + 1]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 2) { // pos 2 -> pos 3
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 1][col + 2]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 3) { // pos 3 -> pos 4
		if (row - 1 < 0 || row - 2  < 0 || col - 1 < 0 || col - 2 < 0) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col - 2]);
		temp.push_back(grid[row][col - 1]);
		temp.push_back(grid[row - 1][col - 1]);
		temp.push_back(grid[row - 2][col - 1]);
		switchBlocks(temp);
		++pos;
	} else if (pos == 4) { // pos 4 -> pos 1
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row - 1][col]);	
		switchBlocks(temp);
		pos = 1;
	}
}

void JBlock::rotateCCW() {
	vector<Cell *> temp;
	int row = lowerleft->getRow();
	int col = lowerleft->getCol();
	if (pos == 1) { // pos 1 -> pos 4
		if (row - 1 < 0 || row - 2 < 0 || col + 1 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 2][col + 1]);
		switchBlocks(temp);
		pos = 4;
	} else if (pos == 4) { // pos 4 -> pos 3
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row - 1][col]);
		temp.push_back(grid[row - 1][col + 1]);
		temp.push_back(grid[row - 1][col + 2]);
		switchBlocks(temp);
		--pos;
	} else if (pos == 3) { // pos 3 -> pos 2
		if (row - 1 < 0 || row - 2 < 0 || col - 1 < 0 || col - 2 < 0) {
			throw InvalidMoveException();
		}
		temp.push_back(grid[row][col - 2]);
		temp.push_back(grid[row - 1][col - 2]);
		temp.push_back(grid[row - 2][col - 2]);
		temp.push_back(grid[row - 2][col - 1]);
		switchBlocks(temp);
		--pos;
	} else if (pos == 2) { // pos 2 -> pos 1
		if (row - 1 < 0 || col + 1 > 10 || col + 2 > 10) {
			throw InvalidMoveException();
		}
		temp.push_back(lowerleft);
		temp.push_back(grid[row][col + 1]);
		temp.push_back(grid[row][col + 2]);
		temp.push_back(grid[row - 1][col]);
		switchBlocks(temp);
		--pos;
	}
}
