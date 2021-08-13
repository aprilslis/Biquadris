#ifndef _SCORE_H_
#define _SCORE_H_

class Score{
    int score;     //current score
    int highscore; //highest score ever achieved

public:
    Score();                   //constructor
    virtual ~Score();          //destructor
    int getScore();            //return current score
    int getHighScore();        //return highest score
    void updateScore(int val); //update the score to be integar val
    void resetScore();         //reset the score
};

#endif
