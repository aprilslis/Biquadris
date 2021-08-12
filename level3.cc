#include "level3.h"

using namespace std;

Block * Level3::generateRandomBlock(int seed, int id) {
	if (!isRandom) {
		if (pos + 1 == len) { //considering it is already initilised with filename
			pos = 0;
		} 
		switch(sequence[pos]) {
			case 'I' :
				++pos;
				return new IBlock{3, id};
			case 'J' :
				++pos;
				return new JBlock{3, id};
			case 'L' :
				++pos;
				return new LBlock{3, id};
			case 'O' :
				++pos;
				return new OBlock{3, id};
			case 'S' :
				++pos;
				return new SBlock{3, id};
			case 'Z' :
				++pos;
				return new ZBlock{3, id};
			case 'T' :
				++pos;
				return new TBlock{3, id};
			default :
				++pos;
				cout<<"not getting a block!!! (level 3)"<<endl;
				return nullptr;
		}
	} else {
    		this->seed = seed;
    		//srand(seed);
    		int random = rand() % 9 + 1;
    		switch(random) {
        	case 1 : 
            		return new IBlock{3, id};
        	case 2 :
       		     	return new JBlock{3, id};
       		case 3:
            		return new LBlock{3, id};
        	case 4 : 
        	    	return new OBlock{3, id};
        	case 5 :
		case 6 :
           		return new SBlock{3, id};
        	case 7 :
		case 8 : 
            		return new ZBlock{3, id};
        	case 9 : 
            		return new TBlock{3, id};
		default :
	    		return nullptr;    
    		}
	}
}

int Level3::getLevel() {
	return 3;
}
