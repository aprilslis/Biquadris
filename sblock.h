#ifndef _SBLOCK_H_
#define _SBLOCK_H_

#include "block.h"

class SBlock : public Block {
  
    int size;                                     //size of block
    int pos;                                      //position of block
    void switchBlocks(std::vector<Cell *> other); //helper function of moveDown()

public:
    SBlock(int level, int i);                                //constructor
    char getType() override;                                 //return the type of block (S)
    void init(std::vector<std::vector<Cell *>> &g) override; //initialize the block
    void lost() override;                                    //check if losing condition has been met
    void moveLeft() override;                                //move block left
    void moveRight() override;                               //move block right
    void moveDown() override;                                //move block down
    void drop() override;                                    //drop the block down
    void rotateCW() override;                                //rorate the block clockwise
    void rotateCCW() override;                               //rotate the block counterclockwise
  
};

#endif
