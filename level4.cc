#include "level4.h"
  
Block * Level4::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 9 + 1;
    switch(random) {
        case 1 :
            return new IBlock{4};
        case 2 :
            return new JBlock{4};
        case 3:
            return new LBlock{4};
        case 4 :
            return new OBlock{4};
        case 5 :
        case 6 :
            return new SBlock{4};
        case 7 :
        case 8 :
            return new ZBlock{4};
        case 9 :
            return new TBlock{4};
        default :
            return nullptr;
    }
}

int Level4::getLevel() {
        return 3;
}

