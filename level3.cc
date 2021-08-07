#include "level3.h"

Block * Level3::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 9 + 1;
    switch(random) {
        case 1 : 
            return new IBlock{3};
        case 2 :
            return new JBlock{3};
        case 3:
            return new LBlock{3};
        case 4 : 
            return new OBlock{3};
        case 5 :
	case 6 :
            return new SBlock{3};
        case 7 :
	case 8 : 
            return new ZBlock{3};
        case 9 : 
            return new TBlock{3};
	default :
	    return nullptr;    
    }
}

int Level3::getLevel() {
	return 3;
}
