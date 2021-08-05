#ifndef _SCORE_H_
#define _SCORE_H_


class Score : public Score {
  
    int score;
    int level;
  
    public:
        Score(int l);
        ~Score();
        int getScore();
        void setLevel(int l);
        void setScoreRowsCleared(int r);
        void setScoreBlockCleared(int l);
  
};
