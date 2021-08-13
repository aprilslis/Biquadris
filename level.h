#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

class Level{
protected:
    std::string sequence; //stores sequence of input(blocks) for current level
    int seed;             //seed of sequence (used when level does not use file input for blocks)
    int len;              //length of sequence
    int pos;              //position of current input block in sequence
    bool isRandom;        //if input is randomized currently

public:
    Level();                                                      //constructor
    virtual ~Level();                                             //destructor
    void init(std::string filename);                              //initialize a level
    virtual Block *generateRandomBlock(int id, int seed = 0) = 0; //generate a block input
    virtual int getLevel() = 0;                                   //return current level
    void setRandom();                                             //set block input to be random
    void setNoRandom();                                           //set block input to be not random
};

#endif
