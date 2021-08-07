#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <cstdlib>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

class Level {
protected:
	int seed;
public:
	virtual void init(std::string filename) = 0;
	virtual Block * generateRandomBlock(int seed = 0) = 0;
	virtual int getLevel() = 0;
	virtual ~Level();
};

#endif
