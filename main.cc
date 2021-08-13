#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
    
    bool onlyText = false;          //stores defaultly that program display both text and graphical display
    int seed = 0;                   //stores default seed
    string file1 = "sequence1.txt"; //stores default file input for player 1
    string file2 = "sequence2.txt"; //store default file input for player 2
    int startLevel = 0;             //store default starting level of game

    for (int i = 1; i < argc; i++){
        string cmd = (string)argv[i];
        if (cmd == "-text") {
            onlyText = true;        
        } 
        else if (cmd == "-seed") {
            seed = stoi(argv[++i]);

        } 
        else if (cmd == "-scriptfile1") {
            file1 = argv[++i];

        } 
        else if (cmd == "-scriptfile2") {
            file2 = argv[++i];

        }
        else if (cmd == "-startlevel") {
            startLevel = stoi(argv[++i]);
            if (startLevel < 0 || startLevel > 4){
                startLevel = 0;     // if invalid level, set it to 0 
            }
        }
    }
    Game g{file1,file2,startLevel};       //initialize game
    if(onlyText) g.displayOnlyText(true); //if onlyText is enabled, set the game to only display text
    g.setSeed(seed);                      //set the game with seed
    srand(seed);
    g.start();                            //start the game

    return 0;
}
