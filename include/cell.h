#ifndef _Cell_ 
#define _Cell_

#include <vector>
#include <iostream>
#include "position.h"
#include "state.h"
#include "lattice.h"

class Cell{
  private:
    Position* position;
    State* state;
    State* nState;
    std::vector<Position> neighbours = { {-1, -1}, {-1, 0}, {-1, 1},
                                         { 0, -1},          { 0, 1},
                                         { 1, -1}, { 1, 0}, { 1, 1}};

  public:

    Cell();
    Cell(Position* position, State* estado);
    ~Cell(void);

    const State& getState(void) const;
    const int getStateInt(void) const;
    void setState(State& estado);

    void setPosition(Position* position);
    Position getPosition(void) const;
    Position getPosition(void);
    
    virtual int nextState(Lattice& lattice) = 0;
    virtual void updateState();
    //virtual ostream& display(ostream&) = 0;
    int countAliveNeighbours(Lattice& lattice);
    //friend ostream& operator<<(ostream&, const Cell&);
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
#endif