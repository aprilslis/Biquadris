#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include "level.h"
#include <string>

class Level3: public Level {
public:
    Block *generateRandomBlock(int id, int seed = 0) override; //generate a block input
    int getLevel() override;                                   //return current level
};

#endif
