#include "level4.h"

using namespace std;

Block *Level4::generateRandomBlock(int id, int seed){
    if (!isRandom){
        if (pos + 1 == len){ //considering it is already initilised with filename
            pos = 0;
        }
        switch (sequence[pos]){
            case 'I':
                ++pos;
                return new IBlock{4, id};
            case 'J':
                ++pos;
                return new JBlock{4, id};
            case 'L':
                ++pos;
                return new LBlock{4, id};
            case 'O':
                ++pos;
                return new OBlock{4, id};
            case 'S':
                ++pos;
                return new SBlock{4, id};
            case 'Z':
                ++pos;
                return new ZBlock{4, id};
            case 'T':
                ++pos;
                return new TBlock{4, id};
            default:
                ++pos;
                cout << "not getting a block!!! (level 4)" << endl; //an error message useful for testing
                return nullptr;
        }
    }
    else{
        this->seed = seed;
        int random = rand() % 9 + 1;
        switch (random){
            case 1:
                return new IBlock{4, id};
            case 2:
                return new JBlock{4, id};
            case 3:
                return new LBlock{4, id};
            case 4:
                return new OBlock{4, id};
            case 5:
            case 6:
                return new SBlock{4, id};
            case 7:
            case 8:
                return new ZBlock{4, id};
            case 9:
                return new TBlock{4, id};
            default:
                return nullptr;
        }
    }
}

int Level4::getLevel(){
    return 4;
}
