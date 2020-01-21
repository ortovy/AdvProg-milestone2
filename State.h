//
// Created by omer on 16/01/2020.
//

#ifndef ADVPROG_MILESTONE2_STATE_H
#define ADVPROG_MILESTONE2_STATE_H

template<typename T>

class State {
    T state;
    double cost;
    double initialCost;
    State<T> *previous;

public:
    State(T s): state(s) {
        this->state = s;
        this->previous = nullptr;
    }
    bool operator==(State<T> *s) {
        return (this->state == s->getStateObj());
    }
    bool operator<(State<T> *s) {
        return (this->cost < s->getStateCost);
    }
    T getStateObj() {
        return this->state;
    }
    void setPrevious(State<T>* pre) {
        previous = pre;
    }
    State<T>* getPrevious() {
        return this->previous;
    }
    void setStateCost(double c) {
        this->cost = c;
    }
    double getStateCost() {
        return this->cost;
    }
    double getStateInitialCost() {
        return this->initialCost;
    }
     void setStateInitialCost(double initCost) {
        this->initialCost = initCost;
    }
};


#endif //ADVPROG_MILESTONE2_STATE_H
