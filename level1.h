#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "level.h" 

class Level1: public Level {
	public:
	Block * generateRandomBlock(int seed) override;
};

#endif