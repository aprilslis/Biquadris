#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include "game.h"

class Display {
	protected:
        	Game g1;
	       	Game g2;
	public:
        	Display(Game *g1, Game *g2);
        	virtual void printDisplay() = 0;
};

#endif
