//
// Created by omer on 16/01/2020.
//

#ifndef ADVPROG_MILESTONE2_STATE_H
#define ADVPROG_MILESTONE2_STATE_H

template<typename T>
/*
 * state is a generic class that defines nodes in our searchable objects.
 */
class State {
    T state;
    double cost;
    double initialCost;
    State<T> *previous;

public:
    //constructor
    State(T s): state(s) {
        this->state = s;
        this->previous = nullptr;
    }
    //overload operator== to compare to states
    bool operator==(State<T> *s) {
        return (this->state == s->getStateObj());
    }
    //overload operator== to compare to states
    bool operator<(State<T> *s) {
        return (this->cost < s->getStateCost);
    }
    //returns the state objects.
    T getStateObj() {
        return this->state;
    }
    //sets a previous state to a given state,
    //this function will help us to make paths
    void setPrevious(State<T>* pre) {
        previous = pre;
    }
    //gets to the state's previous state.
    State<T>* getPrevious() {
        return this->previous;
    }
    //sets cost of a state.
    void setStateCost(double c) {
        this->cost = c;
    }
    // returns state's cost.
    double getStateCost() {
        return this->cost;
    }
    //returns the original cost of a state.
    //in some algorithms we change the state cost during running
    double getStateInitialCost() {
        return this->initialCost;
    }
    // sets state's original cost
     void setStateInitialCost(double initCost) {
        this->initialCost = initCost;
    }
};


#endif //ADVPROG_MILESTONE2_STATE_H
