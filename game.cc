#include <iostream>
#include "game.h"
using namespace std;


Game::Game(): board1{}, board2{}, textdisplay{board1,board2} {
}


bool cmpString(string input, string command){
    return input==command.substr(0,input.size());
}

bool validifyCmd(string input){
    int count=0;
    if(cmpString(input,"left")){
        count++;
    }
    if(cmpString(input,"right")){
        count++;
    }
    if(cmpString(input,"down")){
        count++;
    }
    if(cmpString(input,"clockwise")){
        count++;
    }
    if(cmpString(input,"counterclockwise")){
        count++;
    }
    if(cmpString(input,"levelup")){
        count++;
    }
    if(cmpString(input,"leveldown")){
        count++;
    }
    if(cmpString(input,"drop")){
        count++;
    }
    if(cmpString(input,"I")){
        count++;
    }
    if(cmpString(input,"J")){
        count++;
    }
    if(cmpString(input,"L")){
        count++;
    }
    if(cmpString(input,"restart")){
        count++;
    }
    if(cmpString(input,"hint")){
        count++;
    }
    if(cmpString(input,"random")){
        count++;
    }
    if(cmpString(input,"norandom")){
        count++;
    }
    return count==1;
}

void Game::start(){

    //print welcome messages
    cout<<"Welcome to Biquadris! Input your command:"<<endl;
    

    string input;
    int curNum = 1;
    Grid *cur = &board1;
    cur->addBlock();
    while(cin>>input){

        //take off multipler at the start first
        int multiplier;
        if(!isdigit(input[0])){
            int multiplier = 1;
        }
        else{
            multiplier = 0;
            while(isdigit(input[0])){
                int num = stoi(input.substr(0,1));
                input = input.substr(1,input.size());
                multiplier = multiplier*10 + num;
            }
        }

        
       
        //interpret commands
        try{
            for(int i=0;i<multiplier;i++){

                if(!validifyCmd(input)){//not interpretable command
                    cout<<"Invalid command. Please try again:"<<endl;
                    break;
                }

                if(cmpString(input,"left")){
                    cur->moveBlockLeft();
                }
                else if(cmpString(input,"right")){
                    cur->moveBlockRight();
                }
                else if(cmpString(input,"down")){
                    cur->moveBlockDown();
                }
                else if(cmpString(input,"clockwise")){
                    cur->rotateBlockCW();
                }
                else if(cmpString(input,"counterclockwise")){
                    cur->rotateBlockCCW();
                }
                else if(cmpString(input,"levelup")){
                    cur->levelUp();
                }
                else if(cmpString(input,"leveldown")){
                    cur->levelDown();
                }
                else if(cmpString(input,"drop")){
                    cur->dropBlock();
                    cur->generateBlock();
                    if(curNum==1){
                        cur = &board2;
                        curNum = 2;
                    }
                    else{
                        cur = &board1;
                        curNum = 1;
                    }
                    cur->addBlock();
                }
                else if(cmpString(input,"I")){
                    cur->replaceBlock('i');
                }
                else if(cmpString(input,"J")){
                    cur->replaceBlock('j');
                }
                else if(cmpString(input,"L")){
                    cur->replaceBlock('l');
                }
                else if(cmpString(input,"restart")){
                    //when restart, call end() then restart() and return
                    end();
                    restart();
                    return; //this command should not be done more than 1 time
                }
                else if(cmpString(input,"hint")){
                    //needs to write this funciton in grid
                    break; //this command should not be done more than 1 time
                }
                else if(cmpString(input,"random")){
                    //blabla
                    break; //this command should not be done more than 1 time
                }
                else if(cmpString(input,"norandom")){
                    //blabla
                    break; //this command should not be done more than 1 time
                }
            }
        }
        catch(LostException e1){
            if(curNum==1){
                end(2);
            }
            else{
                end(1);
            }
            restart();
        }
        catch(InvalidMoveException e2){
            //do nothing?
        }
        catch(...){
            cout<<"default error (game)"<<endl;
        }
        

        //check the rows, clear rows, count scores

        
        drawText();
        drawGraphic();
    }
        
    //calls end()
    end();
}

void Game::restart(){
    cout<<"Game starting:"<<endl;
    
    //old boards are delete, new boards is init
    board1.clearGrid();
    board2.clearGrid();//remember to finish clearGrid implementation

}

void Game::end(int winner=0){
    if(winner==0){
        if(board1.getScore()>board2.getScore()){
            cout<<"Player 1 ";
        }
        else{
            cout<<"Player 2 ";
        }
    }
    else{
        if(winner==1){
            cout<<"Player 1 ";
        }
        else{
            cout<<"Player 2 ";
        }
    }
    cout<<"won~"<<endl;
    
}

void Game::drawText(){

}

void Game::drawGraphic(){

}

void Game::setFile1(string file){

}

void Game::setFile2(string file){

}

void Game::setSeed(int seed){
    board1.setSeed(seed);
    board2.setSeed(seed);
}
