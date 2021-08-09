#include "block.h"
#include <iostream>
using namespace std;

Block::Block(int level) {
	this->level = level;
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

bool Block::isHeavy() {
	return heavy;
}

void Block::setHeavy() {
	heavy = true;
}
