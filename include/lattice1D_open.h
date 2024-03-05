#ifndef _LATTICE1D_OPEN_ 
#define _LATTICE1D_OPEN_

#include <iostream>
#include "lattice1D.h"

class Lattice1D_open: public Lattice1D {
  public:
    Lattice1D_open(int size, int initialCellState = 0): Lattice1D(){}
    ~Lattice1D_open(){}

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Open";}

    private:
      //CellACE border;
};

#endif