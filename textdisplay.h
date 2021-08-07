#ifndef _TEXT_DISPLAY_H_
#define _TEXT_DISPLAY_H_

#include "display.h"
#include <string>

class TextDisplay: public Display {
        int height;
        std::string topTextBlock(char next);
        std::string lowTextBlock(char next);
        public:
        TextDisplay(Grid *g1, Grid *g2);
        void printDisplay() override;
};

#endif
