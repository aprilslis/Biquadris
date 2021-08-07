#ifndef _OBLOCK_H_
#define _OBLOCK_H_

#include "block.h"

class OBlock : public Block {
  
    int pos;
    int size;
    void switchBlocks(std::vector<Cell *> other);
    void moveHeavy();
  
    public:
        OBlock(int level);
        char getType() override;
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
