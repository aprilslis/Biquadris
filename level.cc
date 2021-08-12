#include "level.h"

using namespace std;

Level::Level(): pos{-1}, isRandom{true} {}

void Level::init(string filename) {
	ifstream f{filename};
	string seq((istreambuf_iterator<char>(f)),(istreambuf_iterator<char>()));
	this->sequence = seq;
	len = seq.length();
	pos = 0;
}

void Level::setRandom() {
	isRandom = true;
}

void Level::setNoRandom() {
	isRandom = false;
}

Level::~Level(){
    //empty
}
