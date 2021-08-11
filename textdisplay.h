#ifndef _TEXT_DISPLAY_H_
#define _TEXT_DISPLAY_H_

#include "basedisplay.h"
#include <string>

class TextDisplay: public BaseDisplay {
        int height;
        int blind; //records if special effect blind is applied (0 is no one, 1 is player 1, 2 is player 2)
        std::string topTextBlock(char next);
        std::string lowTextBlock(char next);
	std::string printBlind(Grid *g, int row);
        void printNormally() override;
        void printBlindPlayer1() override;
	void printBlindPlayer2() override;

        public:
        TextDisplay(Grid *g1, Grid *g2);
	
};

#endif
