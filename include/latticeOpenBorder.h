#ifndef __LATTICEOPENBORDER__ 
#define __LATTICEOPENBORDER__

#include "../include/lattice.h"
#include "../include/cell.h"

class LatticeOpenBorder: public Lattice{
  public:
    LatticeOpenBorder(int size);
    ~LatticeOpenBorder();

    Cell& getCell(int);
    const Cell& getCell(int) const;
    std::string getName(void){return "Open";}

    private:
      Cell border;
};

#endif