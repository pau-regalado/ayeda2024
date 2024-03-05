#ifndef _Cell_ 
#define _Cell_

#include <vector>
#include <iostream>
#include "position.h"
#include "state.h"
#include "lattice.h"

class Cell{
  private:
    State* state;
    State* nState;
    Position* position;

  public:

    Cell();
    Cell(const Position& position, const State& state);
    ~Cell(void);

    State& getState(void) const;
    void setState(State& state);

    State& getNextState(void) const;
    void setNextState(State& state);

    const int getStateInt(void) const;
    
    Position& getPosition(void) const;
    void setPosition(const Position& position);
    
    virtual int nextState(Lattice& lattice) = 0;
    virtual void updateState();
    std::ostream& display(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
#endif