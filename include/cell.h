#ifndef _CELL_ 
#define _CELL_

#include <vector>
#include <iostream>
#include "position.h"
#include "stateDead.h"
#include "stateAlive.h"

class Lattice;

class Cell{
  protected:
    State* state;
    State* nState;
    Position* position;

  public:

    // Cell();
    Cell(Position& position, State& state);
    ~Cell(void);

    State& getState(void) const;
    void setState(State& state);

    State& getNextState(void) const;
    void setNextState(State& state);

    const int getStateInt(void) const;
    
    Position& getPosition(void) const;
    void setPosition(const Position& position);
    
    virtual int nextState(Lattice& lattice) = 0;
    void updateState();
    std::ostream& display(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
#endif