#ifndef _CELL_H_
#define _CELL_H_

class Cell {

        char type;
        int age;
        int row;
        int col;
        int identity;

        public:
        Cell(int row, int col);
        void setType(char type); 
        char getType();
        int getAge();
        int getRow();
        int getCol();
        void setIdentity(int identity);
        int getIdentity();
        bool isFull();
        void updateAge(); // increments age of cell
        void copyCell(Cell *other); // copies the contents of other
        void clearCell(); // resets the cell
        
};

#endif
