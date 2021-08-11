#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include "block.h"

class SBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);
  
    public:
        SBlock(int level);
	char getType() override;
        void init(std::vector<std::vector<Cell *>> &g) override;
        void lost() override;
        void moveLeft() override;
        void moveRight() override;
        void moveDown() override;
        void drop() override;
        void rotateCW() override;
        void rotateCCW() override;
  
};

#endif
