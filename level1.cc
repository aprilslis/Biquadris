#include "level1.h"

void Level1::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 12 + 1;
    switch(random) {
        case 1 : 
        case 2 : 
            return new IBlock{};
            break;
        case 3 : 
        case 4 :
            return new JBlock{};
            break;
        case 5 : 
        case 6:
            return new LBlock{};
            break;
        case 7 :
        case 8 : 
            return new OBlock{};
            break;
        case 9 : 
        case 10 :
            return new TBlock{};
            break;
        case 11 : 
            return new ZBlock{};
            break;
        case 12 : 
            return new SBlock{};
            break;
    }
} 
