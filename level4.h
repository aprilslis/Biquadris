#ifndef _LEVEL4_H_
#define _LEVEL4_H_

#include "level.h"
#include <string>

class Level4: public Level {
	public:
	Block * generateRandomBlock(int id, int seed = 0) override;
	int getLevel();
};

#endif
