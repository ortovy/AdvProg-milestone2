//
// Created by omer on 16/01/2020.
//

#ifndef ADVPROG_MILESTONE2_CELL_H
#define ADVPROG_MILESTONE2_CELL_H


class Cell {
    int i;
    int j;
public:
    Cell(int i, int j);
    int getRow();
    int getColumn();
    bool operator==(Cell c);
};


#endif //ADVPROG_MILESTONE2_CELL_H
