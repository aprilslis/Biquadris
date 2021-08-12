#ifndef _LBLOCK_H_
#define _LBLOCK_H_

#include "block.h"

class LBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);

    public:
        LBlock(int level, int i);
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
