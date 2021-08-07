#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include "grid.h"

class Display {
	protected:
        	Grid *g1;
	       	Grid *g2;
	public:
        	Display(Grid *g1, Grid *g2);
        	virtual void printDisplay() = 0;
};

#endif
