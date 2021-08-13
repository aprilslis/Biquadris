#ifndef _CELL_H_
#define _CELL_H_

class Cell{

    char type;    //type of block that the cell is currently holding
    int row;      //x position of cell
    int col;      //y position of cell
    int identity; //id of cell

public:
    Cell(int row, int col);         //contructor
    void setType(char type);        //set the type of cell to type
    char getType();                 //get current type of cell
    int getRow();                   //get x position of cell
    int getCol();                   //get y position of cell
    void setIdentity(int identity); //set cell's id to be identity
    int getIdentity();              //get the cell's currently id
    bool isFull();                  //check is cell is foll
    void copyCell(Cell *other);     // copies the contents of the cell, other
    void clearCell();               // resets the cell
};

#endif
