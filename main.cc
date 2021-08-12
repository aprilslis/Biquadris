#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
    
    bool onlyText = false;
    int seed = 0;
    string file1 = "sequence1.txt";
    string file2 = "sequence2.txt";
    int startLevel = 0;
    for (int i = 1; i < argc; i++){
        string cmd = (string)argv[i];
        if (cmd == "-text") {
            onlyText = true;        } 
        else if (cmd == "-seed") {
            seed = stoi(argv[++i]);

        } else if (cmd == "-scriptfile1") {
            file1 = argv[++i];

        } else if (cmd == "-scriptfile2") {
            file2 = argv[++i];

        }
        else if (cmd == "-startlevel") {
            startLevel = stoi(argv[++i]);
            if (startLevel < 0 || startLevel > 4)  {
                startLevel = 0;     // if invalid level, set it to 0 
            }
        }
    }
    Game g{file1,file2,startLevel};
    if(onlyText) g.displayOnlyText(true);
    g.setSeed(seed);
    srand(seed);
    g.start();

    return 0;
}
