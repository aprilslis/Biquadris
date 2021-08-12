#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "level.h" 

class Level1: public Level {
	public:
	Block * generateRandomBlock(int id, int seed = 0) override;
	int getLevel() override;
};

#endif
