#ifndef __LATTICEREFLECTIVEBORDER__ 
#define __LATTICEREFLECTIVEBORDER__

#include "../include/lattice.h"
#include "../include/cell.h"

class LatticeReflectiveBorder: public Lattice{
  public:
    LatticeReflectiveBorder(int row, int col);
    LatticeReflectiveBorder(std::string filename);
    ~LatticeReflectiveBorder();

    Cell& getCell(Position*);
    const Cell& getCell(Position*) const;
    std::string getName(void){return "Reflective";} 

    void nextGenerationSpecific(void) {}
};

#endif