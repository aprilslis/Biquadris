#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include "block.h"

class SBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);
    void moveHeavy();
  
    public:
        SBlock(int level);
	char getType();
        void init(std::vector<std::vector<Cell *>> &g) override;
        void lost() override;
        void moveLeft() override;
        void moveRight() override;
        void moveDown() override;
	void moveHeavyDown() override;
        void drop() override;
        void rotateCW() override;
        void rotateCCW() override;
  
};

#endif
