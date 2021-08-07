#include <iostream>
#include <sstream>
#include <fstream>
#include "game.h"
using namespace std;


Game::Game(): board1{}, board2{}, onlyText{false}, textdisplay{&board1,&board2} {
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
    if(cmpString(input,"sequence")){
        count++;
    }
    return count==1;
}

void Game::start(int startlevel=0){

    //print welcome messages
    cout<<"Welcome to Biquadris! Input your command:"<<endl;
    
    board1.setLevelNum(startlevel);
    board2.setLevelNum(startlevel);

    string input;
    int curNum = 1;
    Grid *cur = &board1;
    cur->addBlock();
    while(true){
        if(useSeqFile){
            if(!(seqFile>>input)){
                input = "";
                useSeqFile = false;
            }
        }
        else{
            if(!(cin>>input)){
                break;
            }
        }
        

        //take off multipler at the start first
        int multiplier;
        if(input==""){
            multiplier = 0;
        }
        else if(!isdigit(input[0])){
            multiplier = 1;
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

                else if(cmpString(input,"left")){
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
                    //check special effects here 
                    //if yes: specialEffects(curNum);
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
                else if(cmpString(input,"O")){
                    cur->replaceBlock('o');
                }
                else if(cmpString(input,"S")){
                    cur->replaceBlock('s');
                }
                else if(cmpString(input,"T")){
                    cur->replaceBlock('t');
                }
                else if(cmpString(input,"Z")){
                    cur->replaceBlock('z');
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
                    string newfile;
                    cin>>newfile;
                    //do something to switch off random
                    cur->changeFile(newfile);
                    break; //this command should not be done more than 1 time
                }
                else if(cmpString(input,"sequence")){
                    string file;
                    cin>>file;
                    ifstream fileInput(file);
                    string s;
                    while(getline(fileInput,s)){
                        seqFile << s << endl;
                    }
                    useSeqFile = true;
                    break;
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
        
        //display stuffs
        if(multiplier!=0){
            if(onlyText){
                drawText();
            }
            else{
                drawText();
                drawGraphic();
            }
        }
    }
        
    //calls end()
    end();
}

void Game::specialEffects(int curNum){
    string input;
    cin>>input;

    if(cmpString(input,"blind")){//should opperate on curNum
        //do something
    }
    else if(cmpString(input,"heavy")){
        //do something
    }
    else if(cmpString(input,"force")){
        //do something
    }
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
    textdisplay.printDisplay();
}

void Game::drawGraphic(){

}




void Game::displayOnlyText(bool t){
    onlyText = t;
}

void Game::setDefaultFile1(string file){
    board1.setDefaultFile(file);
}

void Game::setDefaultFile2(string file){
    board2.setDefaultFile(file);
}

void Game::setSeed(int seed){
    board1.setSeed(seed);
    board2.setSeed(seed);
}
