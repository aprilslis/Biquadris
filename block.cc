#include "block.h"

void Block::emptyBlock() {
  for (int i = 0; i < (int)block.size(); i++) {
    block[i].setType('\0');
  }
}
