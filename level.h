#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

class Level {
	int seed;
public:
	virtual Block * generateBlock();
	virtual void setSeed(int);
	virtual int getLevel();
};

#endif
