#include "basedisplay.h"
#include <iostream>
using namespace std;

BaseDisplay::BaseDisplay(Grid *g1, Grid *g2): g1{g1}, g2{g2}, blind{0} {}

void BaseDisplay::printDisplay(){
    if(blind==0){
        printNormally();
    }
    else if(blind==1){
        printBlindPlayer1();
    }
    else if(blind==2){
        printBlindPlayer2();
    }
    else{
        cout<<"error occured in textdisplay"<<endl;
    }
}

void BaseDisplay::setBlind(int blindness){
    blind = blindness;
}
