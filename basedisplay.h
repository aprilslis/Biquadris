#ifndef _BASE_DISPLAY_H_
#define _BASE_DISPLAY_H_

#include <iostream>
#include "grid.h"

class BaseDisplay {
	protected:
		Grid *g1;
		Grid *g2;
		int blind;
		virtual void printNormally() = 0;
		virtual void printBlindPlayer1() = 0;
		virtual void printBlindPlayer2() = 0;
	public:
        BaseDisplay(Grid *g1, Grid *g2);
		void printDisplay();
		void setBlind(int blindness);
        	
};

#endif
