#ifndef _LATTICE1D_OPEN_ 
#define _LATTICE1D_OPEN_

#include <iostream>
#include "lattice1D.h"

class Lattice1D_open: public Lattice1D {
  public:
    Lattice1D_open(const char* filename, const FactoryCell& f, int initialCellState = 0);
    ~Lattice1D_open();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "Open";}
    void nextGenerationSpecific(void) {}

    private:
      Cell* border;
};

#endif