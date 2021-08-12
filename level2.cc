#include <fstream>
#include <string.h>
#include "level2.h"
using namespace std;

Block * Level2::generateRandomBlock(int seed) {
    this->seed = seed;
    //srand(seed);
    int random = rand() % 7 + 1;
    switch(random) {
        case 1 : 
            return new IBlock{2};
        case 2 :
            return new JBlock{2};
        case 3:
            return new LBlock{2};
        case 4 : 
            return new OBlock{2};
        case 5 :
            return new SBlock{2};
        case 6 : 
            return new ZBlock{2};
        case 7 : 
            return new TBlock{2};
	default :
	    return nullptr;    
    }
} 

int Level2::getLevel() {
	return 2;
}
