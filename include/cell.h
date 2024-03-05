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

  public:

    Cell();
    Cell(const State& state);
    ~Cell(void);

    const State& getState(void) const;
    const int getStateInt(void) const;
    void setState(State& estado);
    void setPosition(Position* position);
    Position getPosition(void);
    
    virtual int nextState(Lattice& lattice) = 0;
    virtual void updateState();
    virtual std::ostream& display(std::ostream&) = 0;
    virtual int countAliveNeighbours(Lattice& lattice) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
#endif