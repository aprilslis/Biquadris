#include "cell.h"

using namespace std;

Cell::Cell(int row, int col): type{'\0'}, age{0}, row{row}, col{col} {} // '\0' reperesents no type 

void Cell::setType(char type) {
        this->type = type;
}

char Cell::getType() {
        return type;
}

int Cell::getAge() {
        return age;
}

int Cell::getRow() {
        return row;
}

int Cell::getCol() {
        return col;
}

bool Cell::isFull() {
        return (type != '\0');
}

void Cell::updateAge() {
        ++age;
}

void Cell::copyCell(Cell *other) {
        type = other->type;
        age = other->age;
}

void Cell::clearCell() {
        type = '\0';
        age = 0;
}
