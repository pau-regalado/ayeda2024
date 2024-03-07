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
    void setPosition(Position& position);
    
    virtual int nextState(Lattice& lattice) = 0;
    void updateState();
    std::ostream& display(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

    Cell& operator=(const Cell& other) {
    if (this != &other) { // Verifica si no estás asignando el mismo objeto
        // Asigna el estado actual
        state = &other.getState();

        // Asigna el estado siguiente
        nState = &other.getNextState();

        // Asigna la posición
        position = &other.getPosition();
    }
    return *this;
}
};
#endif