#include "block.h"
#include <iostream>
using namespace std;

Block::Block(int level, int i) : identity{i} {
	this->level = level;
	heavy = false;
}

Block::~Block(){
  
}

void Block::emptyBlock() {
    for (int i = 0; i < (int)block.size(); i++) {
        block[i]->setType('\0');
        block[i]->setIdentity(0);
    }
}

int Block::getLevel() {
	return level;
}

void Block::setIdentity(int identity) {
	this->identity = identity;
}


void Block::setHeavy() {
	heavy = true;
}

void Block::moveHeavy() {
	if (level == 4 || level == 3) { // if is block is heavy from level effect
		moveDown();
	}
	if(heavy){ //if block is heavy from special effects
		moveDown();
		moveDown();
		heavy = false;
	}
}

void Block::setLevel(int l){
	level = l;
}

