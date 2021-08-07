#ifndef _SCORE_H_
#define _SCORE_H_


class Score {
    int score;
    int highscore;
  public:
    Score();
    int getScore();
	int getHighScore();
	void updateScore(int val);
	void resetScore();
	virtual ~Score();
  
};

#endif
