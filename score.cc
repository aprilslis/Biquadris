#include "score.h"

using namespace std;

Score::Score(int l) : score{0}, level{l} {}

Score::~Score() {}

int Score::getScore() {
    return score;
}

void Score::setLevel(int l) {
    level = l;
}

void Score::setScoreRowsCleared(int r {
    int rowScore = level + r * r; 
    score += rowScore;
}

void setScoreBlockCleared(int l) {
    int blockScore = (l + 1) * (l + 1);
    score += blockScore;
}
