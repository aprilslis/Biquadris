#include <fstream>
#include <string.h>
#include "level1.h"
using namespace std;

Block * Level1::generateRandomBlock(int id, int seed) {
    this->seed = seed;
    int random = rand() % 12 + 1;
    switch(random) {
        case 1 : 
        case 2 : 
            return new IBlock{1, id};
        case 3 : 
        case 4 :
            return new JBlock{1, id};
        case 5 : 
        case 6:
            return new LBlock{1, id};
        case 7 :
        case 8 : 
            return new OBlock{1, id};
        case 9 : 
        case 10 :
            return new TBlock{1, id};
        case 11 : 
            return new ZBlock{1, id};
        case 12 : 
            return new SBlock{1, id};
        default :
	    return nullptr;
    }
} 

int Level1::getLevel() {
        return 1;
}
