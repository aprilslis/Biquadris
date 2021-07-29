#ifndef _CELL_H_
#define _CELL_H_

class Cell {

        char type;
        int age;
        int row;
        int col;

        public:
        Cell(int row, int col);
        void setType(char type);
        char getType();
        int getAge();
        int getRow();
        int getCol();
        bool isFull();
        void updateAge();
        void swapCell(Cell *other);
        void clearCell();

};

#endif
