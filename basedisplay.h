#ifndef _BASE_DISPLAY_H_
#define _BASE_DISPLAY_H_

#include <iostream>
#include "grid.h"

class BaseDisplay{
protected:
    Grid *g1;  //player 1's game board
    Grid *g2;  //player 2's game board
    int blind; //check if special effect, blind, is enabled and enabled on which person
               //(0 = no player, 1 = player 1 is blinded, 2 = player 2 is blinded)

public:
    BaseDisplay(Grid *g1, Grid *g2);      //constructor
    virtual void printNormally() = 0;     //print board when no one is blinded
    virtual void printBlindPlayer1() = 0; //print board when player 1 is blinded
    virtual void printBlindPlayer2() = 0; //print board when player 2 is blinded
    void printDisplay();                  //print out the current game
    void setBlind(int blindness);         //set the blind field to correspond with blind special effect
};

#endif
