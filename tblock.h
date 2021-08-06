#ifndef _TBLOCK_H_
#define _TBLOCK_H_

#include "block.h"

class TBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);
  
    public:
        TBlock(int level);
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
