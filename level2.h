#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "level.h" 

class Level2: public Level {
	public:
	void init(std::string filename) override;
	Block * generateRandomBlock(int seed) override;
	int getLevel() override;
};

#endif
