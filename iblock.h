#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "block.h"

class IBlock : public Block{

    int size;                                     //size of block
    int pos;                                      //position of block
    void switchBlocks(std::vector<Cell *> other); //helper function of moveDown()

public:
    IBlock(int level, int i);                                //constructor
    char getType() override;                                 //return the type of block (I)
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
