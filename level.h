#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <cstdlib>
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
	virtual Block * generateRandomBlock(int seed = 0);
};

#endif
