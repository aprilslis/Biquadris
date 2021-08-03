#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "level.h" 

class Level2: public Level {
	public:
	Block * generateRandomBlock(int seed) override;
};

#endif
