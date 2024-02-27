#ifndef __LATTICEPERIODICBORDER__ 
#define __LATTICEPERIODICBORDER__

#include "../include/lattice.h"
#include "../include/cell.h"

class LatticePeriodicBorder: public Lattice{
  public:
    LatticePeriodicBorder(int row, int col);
    ~LatticePeriodicBorder();

    Cell& getCell(Position);
    const Cell& getCell(Position) const;
    std::string getName(void){return "Periodic";}
};

#endif