#include <iostream>
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
        string cmdin;
        cmdin = {argv[i]};
        if (cmdin == "-text") {
            displayTextOnly(); 
        } 
        else if (cmdin == "-seed") {
            istringstream ss(argv[i++]);
            int seedin;
            ss >> seedin;
            if (seed > 0){
                setSeed(seedin);
                srand(seed);
            }
        } else if (cmdin == "-scriptfile1") {
            istringstream ss(argv[i++]); 
            string fname; 
            ss >> fname; 
            setScript1(fname); 
        } else if (cmdin == "-scriptfile2") {
            istringstream ss(argv[i++]); 
            string fname; 
            ss >> fname; 
            setScript2(fname);    
        }
        else if (cmdin == "-startlevel") {
            int lvlin;
            istringstream ss(argv[i++]);
            ss >> lvlin; 
            if (lvlin >= 0 && lvlin <= 4)  {
                setStartLevel(lvlin); 
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
