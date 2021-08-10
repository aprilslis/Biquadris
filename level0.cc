#include <fstream>
#include <iostream>
#include <string.h>
#include "level0.h" 

using namespace std;

Block * Level0::generateRandomBlock(int seed) {

	if (pos + 1 > len) {
		pos = 0;
	}
	switch(sequence[pos]) {
		case 'I' : 
			++pos;
			return new IBlock{0};
		case 'J' :
			++pos;
			return new JBlock{0};
		case 'L' :
			++pos;
			return new LBlock{0};
		case 'O' :
			++pos;
			return new OBlock{0};
		case 'S' :
			++pos;
			return new SBlock{0};
		case 'Z' :
			++pos;
			return new ZBlock{0};
		case 'T' :
			++pos;
			return new TBlock{0};
		default :
			++pos;
			cout<<"not getting a block!!! (level 0)"<<endl;
			return nullptr;
	}
}

int Level0::getLevel() {
	return 0;
}





