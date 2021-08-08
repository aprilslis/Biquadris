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
    int startLevel = 0;
    for (int i = 1; i < argc; i++){
        string cmd;
        cmd = {argv[i]};
        if (cmd == "-text") {
            g.displayOnlyText(true); 
        } 
        else if (cmd == "-seed") {
            istringstream ss(argv[++i]);
            int seed;
            ss >> seed;
            g.setSeed(seed);
        } else if (cmd == "-scriptfile1") {
            istringstream ss(argv[++i]); 
            string fname; 
            ss >> fname; 
            g.setDefaultFile1(fname); 
        } else if (cmd == "-scriptfile2") {
            istringstream ss(argv[++i]); 
            string fname; 
            ss >> fname; 
            g.setDefaultFile2(fname);    
        }
        else if (cmd == "-startlevel") {
            istringstream ss(argv[i++]);
            ss >> startLevel; 
            if (startLevel < 0 || startLevel > 4)  {
                startLevel = 0;     // if invalid level, set it to 0 
            }
        }
        g.start(startLevel);
        g.draw();
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
