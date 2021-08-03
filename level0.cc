#include "level0.h" 

using namespace std;

void Level0::init(string sequence) {
	this->sequence = sequence;
	len = sequence.length();
	pos = 0;
}

Block * Level0::generateRandomBlock(int seed) {
	if (pos + 1 > len) {
		pos = 0;
	}
	switch(sequence[pos]) {
		case 'I' : 
			++pos;
			return new IBlock{};
		case 'J' :
			++pos;
			return new JBlock{};
		case 'L' :
			++pos;
			return new LBlock{};
		case 'O' :
			++pos;
			return new OBlock{};
		case 'S' :
			++pos;
			return new SBlock{};
		case 'Z' :
			++pos;
			return new ZBlock{};
		case 'T' :
			++pos;
			return new TBlock{};
		default :
			++pos;
			return nullptr;
	}
}







