#ifndef _Cell_ 
#define _Cell_

#include <vector>
#include <iostream>
#include "position.h"
#include "state.h"
#include "lattice.h"

class Cell{
  private:
    Position position;
    State* state;
    State* nState;
    std::vector<Position> neighbours = { {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {1, 1}, {1, 0}, {0, 1}, {-1, 1} };

  public:
  
    Cell();
    Cell(Position& position, State* estado);
    ~Cell(void);

    const State& getState(void) const;
    const int getStateInt(void) const;
    void setState(State& estado);

    void setPosition(const Position position);
    Position getPosition(void) const;
    Position getPosition(void);
    
    void updateState();
    int nextState(const Lattice&);
    int countAliveNeighbours(const Lattice& lattice);

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};
#endif