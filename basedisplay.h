#ifndef _BASE_DISPLAY_H_
#define _BASE_DISPLAY_H_

#include <iostream>
#include "grid.h"

class BaseDisplay {
	protected:
        	Grid *g1;
	       	Grid *g2;
	public:
        	BaseDisplay(Grid *g1, Grid *g2);
        	virtual void printDisplay() = 0;
};

#endif
