#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include "cell.h"

class Block{
protected:
    Cell *lowerleft;                       // contains the lower-left corner cell
    std::vector<Cell *> block;             // contains all cells in current block
    std::vector<std::vector<Cell *>> grid; // stores the game board
    int level;                             // stores current level of block
    int identity;                          // stores identity
    bool heavy;

public:
    Block(int level, int i);                                    //constructor
    virtual ~Block();                                           //destructor
    virtual char getType() = 0;                                 //return type of the block (ie. J,I,L,etc)
    virtual void init(std::vector<std::vector<Cell *>> &g) = 0; //initialize a block
    virtual void lost() = 0;                                    //check if losing condition has been met
    virtual void moveLeft() = 0;                                //move block left
    virtual void moveRight() = 0;                               //move block right
    virtual void moveDown() = 0;                                //move block down
    virtual void drop() = 0;                                    //drop the block down
    virtual void rotateCW() = 0;                                //rorate the block clockwise
    virtual void rotateCCW() = 0;                               //rotate the block counterclockwise
    void emptyBlock();                                          //make the block empty
    int getLevel();                                             //return the level of block that was created in
    void setHeavy();                                            //enable heavy special effect
    void setIdentity(int identity = 0);                         //set the block's identity to be identity
    void moveHeavy();                                           //move down if block is heavy
    void setLevel(int l);                                       //changes level of block when level of games changes
};

class InvalidMoveException{}; // raised if move is invalid
class LostException{}; // raised if losing condition triggered

#endif
