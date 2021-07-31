#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include "block.h"

class JBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);
  
    public:
        void init(std::vector<std::vector<Cell *>> g) override;
        void lost() override;
        void moveLeft() override;
        void moveRight() override;
        void moveDown() override;
        void drop() override;
        void rotationCW() override;
        void rotationCCW() override;
  
};

#endif
