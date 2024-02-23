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
    State state;
    State* nextState_;

  public:
    Cell();
    Cell(Position& position, State& estado);
    ~Cell(void);

    const State& getState(void) const;
    const int getStateValue(void) const;
    void setState(State& estado);

    void setPosition(const Position position);
    Position getPosition(void) const;
    Position getPosition(void);

    int nextState(const Lattice&);
    void updateState();

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

};

#endif