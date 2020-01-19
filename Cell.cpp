//
// Created by omer on 16/01/2020.
//

#include "Cell.h"

Cell::Cell(int i, int j) {
    this->i = i;
    this->j = j;
}
int Cell:: getRow() {
    return i;
}
int Cell:: getColumn() {
    return j;
}
bool Cell::operator==(Cell c) {
    return (i == c.getRow() && j == c.getColumn());
}