#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
    Game g;
    int startLevel = 0;
    for (int i = 1; i < argc; i++){
        string cmd = (string)argv[i];
        if (cmd == "-text") {
            g.displayOnlyText(true); 
        } 
        else if (cmd == "-seed") {
            // istringstream ss(argv[++i]);
            // int seed;
            // ss >> seed;

            int seed = stoi(argv[++i]);
            g.setSeed(seed);
        } else if (cmd == "-scriptfile1") {
            // istringstream ss(argv[++i]); 
            // string fname; 
            // ss >> fname;

            string fname = argv[++i];
            g.setDefaultFile1(fname); 
        } else if (cmd == "-scriptfile2") {
            // istringstream ss(argv[++i]); 
            // string fname; 
            // ss >> fname; 

            string fname = argv[++i];
            g.setDefaultFile2(fname);    
        }
        else if (cmd == "-startlevel") {
            // istringstream ss(argv[i++]);
            // ss >> startLevel; 

            startLevel = stoi(argv[++i]);
            if (startLevel < 0 || startLevel > 4)  {
                startLevel = 0;     // if invalid level, set it to 0 
            }
        }
    }
    g.start(startLevel);

    return 0;
}
