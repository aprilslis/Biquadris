#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "level.h"

class Level2 : public Level{
public:
    Block *generateRandomBlock(int id, int seed = 0) override; //generate a block input
    int getLevel() override;                                   //return current level
};

#endif
