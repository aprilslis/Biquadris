#include <fstream>
#include <string.h>
#include "level1.h"
using namespace std;

void Level1::init(string filename){

}

Block * Level1::generateRandomBlock(int seed) {
    this->seed = seed;
    srand(seed);
    int random = rand() % 12 + 1;
    switch(random) {
        case 1 : 
        case 2 : 
            return new IBlock{1};
        case 3 : 
        case 4 :
            return new JBlock{1};
        case 5 : 
        case 6:
            return new LBlock{1};
        case 7 :
        case 8 : 
            return new OBlock{1};
        case 9 : 
        case 10 :
            return new TBlock{1};
        case 11 : 
            return new ZBlock{1};
        case 12 : 
            return new SBlock{1};
        default :
	    return nullptr;
    }
} 

int Level1::getLevel() {
        return 1;
}
