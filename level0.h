#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include "level.h"
#include <string>

class Level0 : public Level{
public:
    Block *generateRandomBlock(int id, int seed = 0) override; //generate a block input
    int getLevel() override;                                   //return current level
};

#endif
