#include "level1.h"

Block * Level1::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 12 + 1;
    switch(random) {
        case 1 : 
        case 2 : 
            return new IBlock{};
        case 3 : 
        case 4 :
            return new JBlock{};
        case 5 : 
        case 6:
            return new LBlock{};
        case 7 :
        case 8 : 
            return new OBlock{};
        case 9 : 
        case 10 :
            return new TBlock{};
        case 11 : 
            return new ZBlock{};
        case 12 : 
            return new SBlock{};
        default :
	    return nullptr;
    }
} 

int Level1::getLevel() {
        return 1;
}
