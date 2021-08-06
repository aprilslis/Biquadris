#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include "cell.h"

class Block {

        protected:
        Cell *lowerleft; // contains the lower-left corner cell
        std::vector <Cell *> block; // contains all cells in current block
        std::vector<std::vector<Cell *>> grid; // stores the game board
        int level; // stores current level of block
	int identity; // stores identity
        public:
	Block(int level);
	virtual ~Block();
        virtual void init(std::vector<std::vector<Cell *>> &g) = 0; 
        virtual void lost() = 0;
        virtual void moveLeft() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void drop() = 0;
        virtual void rotateCW() = 0;
        virtual void rotateCCW() = 0;
        void emptyBlock();
	int getLevel();
	void setIdentity(int identity);

};

class InvalidMoveException {}; // raised if move is invalid
class LostException {}; // raised if losing condition triggered

#endif
