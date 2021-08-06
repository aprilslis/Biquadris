#include "oblock.h"
using namespace std;

OBlock::OBlock(int level): Block{level} {}

void OBlock::switchBlocks(vector<Cell *> other) {
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
                    block[j]->setType('O');
                    block[j]->setIdentity(identity);
             }
             throw InvalidMoveException();
        }
    } 

    //doing the switch 
    block.clear();
    block = other;
    for (int i = 0; i < size; i++) {
            block[i]->setType('O');
            block[i]->setIdentity(identity);
    }
    lowerleft = other[0];
}

void OBlock::init(std::vector<std::vector<Cell *>> &g) {
    grid = g;
    pos = 1;
    size = 4;
    lost();
    lowerleft = grid[3][0];
    block.push_back(lowerleft);
    block.push_back(grid[3][1]);
    block.push_back(grid[2][0]);
    block.push_back(grid[2][1]);
    for (int i = 0; i < size; i++) {
        block[i]->setType('O');
        block[i]->setIdentity(identity);
    }
}



void OBlock::lost() {
    if (grid[3][0]->isFull() || grid[3][1]->isFull() || grid[2][0]->isFull() || grid[2][1]->isFull()) {
        throw LostException();
    }
}

void OBlock::moveLeft() {
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
}

void OBlock::moveRight() {
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
}

void OBlock::moveDown() {
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

void OBlock::drop() {
    try {
        while(true) {
            moveDown();
        }
    } catch (InvalidMoveException &e) {
    }
}

void OBlock::rotateCW() {
    return; // rotation does not affect spatial configuration
}

void OBlock::rotateCCW() {
    return; // rotation does not affect spatial configuration
}
