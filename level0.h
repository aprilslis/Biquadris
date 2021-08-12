#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include "level.h"
#include <string>

class Level0: public Level {
public:
	Block * generateRandomBlock(int seed = 0, id) override;
	int getLevel() override;
};

#endif
