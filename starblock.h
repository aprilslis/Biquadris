#ifndef _STARBLOCK_H_
#define _STARBLOCK_H_

#include "block.h"

class StarBlock : public Block {

    void switchBlocks(); //helper function of moveDown()

public:
    StarBlock(int level, int i);                             //constructor
    char getType() override;                                 //return the type of block (*)
    void init(std::vector<std::vector<Cell *>> &g) override; //initialize the block
    void lost() override;                                    //check if losing condition has been met
    void moveLeft() override;                                //not used
    void moveRight() override;                               //not used
    void moveDown() override;                                //not used
    void drop() override;                                    //drop the block down
    void rotateCW() override;                                //not used
    void rotateCCW() override;                               //not used

};

#endif
