//
// Created by omer on 16/01/2020.
//

#ifndef ADVPROG_MILESTONE2_STATE_H
#define ADVPROG_MILESTONE2_STATE_H

template<typename T>

class State {
    T state;
    double cost;
    State<T> *previous;
    double firstCost;

public:
        State(T s): state(s) {
        this->state = s;
        this->previous = nullptr;
        this->cost = -1;
        this->firstCost = -1;
    }
    bool operator==(State<T> *s) {
        return (this->state == s->getStateObj());
    }
    T getStateObj() {
        return this->state;
    }
     double getCost() {
        return cost;
    }
    void setPrevious(State<T>* pre) {
        previous = pre;
    }
};


#endif //ADVPROG_MILESTONE2_STATE_H
