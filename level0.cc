#include <fstream>
#include <iostream>
#include <string.h>
#include "level0.h" 

using namespace std;

Block * Level0::generateRandomBlock(int seed, int id) {

	if (pos + 1 == len) {
		pos = 0;
	}

	cout<<sequence[pos]<<endl;

	switch(sequence[pos]) {
		case 'I' : 
			++pos;
			return new IBlock{0, id};
		case 'J' :
			++pos;
			return new JBlock{0, id};
		case 'L' :
			++pos;
			return new LBlock{0, id};
		case 'O' :
			++pos;
			return new OBlock{0, id};
		case 'S' :
			++pos;
			return new SBlock{0, id};
		case 'Z' :
			++pos;
			return new ZBlock{0, id};
		case 'T' :
			++pos;
			return new TBlock{0, id};
		default :
			++pos;
			cout<<"not getting a block!!! (level 0)"<<endl;
			return nullptr;
	}

}

int Level0::getLevel() {
	return 0;
}





