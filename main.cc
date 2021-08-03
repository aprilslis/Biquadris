#include <iostream>
#include "grid.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
using namespace std;



int main(){
    
    Grid g;
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
}
