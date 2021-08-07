#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "level.h" 

class Level1: public Level {
	public:
	void init(std::string filename) override;
	Block * generateRandomBlock(int seed = 0) override;
	int getLevel() override;
};

#endif
