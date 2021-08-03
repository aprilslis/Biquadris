#include "level2.h"

void Level2::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 7 + 1;
    switch(random) {
        case 1 : 
            return new IBlock{};
            break;
        case 2 :
            return new JBlock{};
            break;
        case 3:
            return new LBlock{};
            break;
        case 4 : 
            return new OBlock{};
            break;
        case 5 :
            return new SBlock{};
            break;
        case 6 : 
            return new ZBlock{};
            break;
        case 7 : 
            return new TBlock{};
            break;
    }
} 
