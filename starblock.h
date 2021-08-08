#ifndef _STARBLOCK_H_
#define _STARBLOCK_H_

#include "block.h"

class StarBlock : public Block {

    void switchBlocks();

    public:
        StarBlock();
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
