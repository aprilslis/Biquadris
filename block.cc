#include "block.h"

Block::Block(int level) {
	this->level = level;
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

void Block::isHeavy() {
	return (level == 3);
}
