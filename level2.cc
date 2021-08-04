#include "level2.h"

Block * Level2::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 7 + 1;
    switch(random) {
        case 1 : 
            return new IBlock{};
        case 2 :
            return new JBlock{};
        case 3:
            return new LBlock{};
        case 4 : 
            return new OBlock{};
        case 5 :
            return new SBlock{};
        case 6 : 
            return new ZBlock{};
        case 7 : 
            return new TBlock{};
	default :
	    return nullptr;    
    }
} 
