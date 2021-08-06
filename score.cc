#include "score.h"

using namespace std;

Score::Score() : score{0}, highscore{0} {}

Score::~Score() {}

int Score::getScore() {
	return score;
}

int Score::getHighScore() {
	return highscore;
}

void Score::updateScore(int val) {
	score += val;
	if (score > highscore) {
		highscore = score;
	}
} 

void Score::resetScore() {
	score = 0;
}
