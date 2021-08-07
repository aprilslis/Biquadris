#include <iostream>
#include <sstream>
#include "game.h"
#include "grid.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

using namespace std;



int main(int argc, char *argv[]){
    Game g;
    g.start();
    for (int i = 1; i < argc; i++){
        string cmd;
        cmd = {argv[i]};
        if (cmd == "-text") {
            //displayTextOnly(); 
        } 
        else if (cmd == "-seed") {
            istringstream ss(argv[i++]);
            int seed;
            ss >> seed;
            if (seed > 0){
                setSeed(seed);
                srand(seed);
            }
        } else if (cmd == "-scriptfile1") {
            istringstream ss(argv[i++]); 
            string fname; 
            ss >> fname; 
            setScript1(fname); 
        } else if (cmd == "-scriptfile2") {
            istringstream ss(argv[i++]); 
            string fname; 
            ss >> fname; 
            setScript2(fname);    
        }
        else if (cmd == "-startlevel") {
            int lvlin;
            istringstream ss(argv[i++]);
            ss >> lvl; 
            if (lvl >= 0 && lvl <= 4)  {
                //setStartLevel(lvl); 
            }
        }
    }

    // testing:
    /*Grid g;
    g.printGrid();
    cout<<"---------------------------------------"<<endl;

    IBlock *i = new IBlock{};
    JBlock *j = new JBlock{};
    LBlock *l = new LBlock{};
    OBlock *o = new OBlock{};
    TBlock *t = new TBlock{};
    ZBlock *z = new ZBlock{};
    SBlock *s = new SBlock{};
    
    g.addBlock(i);
    i->moveRight();
    i->drop();
    g.printGrid();
    */ 
    return 0;
}
