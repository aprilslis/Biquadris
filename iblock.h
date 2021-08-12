#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "block.h"

class IBlock : public Block {

	int size;
	int pos;
    	void switchBlocks(std::vector<Cell *> other);

    public:

        IBlock(int level, int i);
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
