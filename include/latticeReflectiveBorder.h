#ifndef __LATTICEREFLECTIVEBORDER__ 
#define __LATTICEREFLECTIVEBORDER__
#include "../include/lattice.h"
#include "../include/cell.h"

class LatticeReflectiveBorder: public Lattice{
  public:
    LatticeReflectiveBorder(int size);
    ~LatticeReflectiveBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Reflective";} 
};

#endif
