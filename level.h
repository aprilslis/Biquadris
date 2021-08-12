#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"

class Level {
protected:
	std::string sequence;
	int seed;
	int len;
	int pos;
	bool isRandom;
public:
	Level();
	void init(std::string filename);
	virtual Block * generateRandomBlock(int seed = 0, int id) = 0;
	virtual int getLevel() = 0;
	virtual ~Level();
	void setRandom();
	void setNoRandom();
};

#endif
