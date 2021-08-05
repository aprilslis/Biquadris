#include "block.h"

void Block::emptyBlock() {
  for (int i = 0; i < (int)block.size(); i++) {
    block[i]->setType('\0');
  }
}

void Block::setLevel(int level) {
	this->level = level;
}

int Block::getLevel() {
	return level;
}
