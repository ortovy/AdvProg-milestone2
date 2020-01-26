//
// Created by omer on 16/01/2020.
//

#include "Cell.h"
//cell class helps us handle states,
//each cell contains the x,y axis values in a matrix.
Cell::Cell(int i, int j) {
    this->row = i;
    this->column = j;
}
int Cell:: getRow() {
    return row;
}
int Cell:: getColumn() {
    return column;
}
//overload the operator== method to check if 2 cells are equals.
bool Cell::operator==(Cell c) {
    return (row == c.getRow() && column == c.getColumn());
}