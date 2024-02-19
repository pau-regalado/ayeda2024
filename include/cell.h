#ifndef _Cell_ 
#define _Cell_

#include <vector>
#include <iostream>
#include "enum.h"
#include "position.h"

class State;
class Lattice;

class Cell{
  private:
    //int vecinas_vivas_;
    Position position_;
    State* estado_; // Apunta a un tipo de estado en concreto para  polimorfismo

  public:
    std::vector<int> vecinas_;

    Cell();
    Cell(Position& position, State* estado = nullptr);
    ~Cell(void);

    State const* getState(void) const;
    int getVivas(void);
    std::vector<int>& getVecinas(void);

    void clearVecinas(void);

    void setState(State *estado);
    void setPosition(const Position position);

    Position getPosition(void) const;
    Position getPosition(void);

    void updateState(void);
    void neighbors(const Grid& g);

};

std::ostream& operator<<(std::ostream& os, const Cell& cell);

#endif