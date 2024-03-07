#ifndef _LATTICE2D_OPEN_ 
#define _LATTICE2D_OPEN_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_open: public Lattice2D {
  public:
    Lattice2D_open(const char* filename, const FactoryCell& f, int initialCellState = 0);
    ~Lattice2D_open();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "Open";}
    void nextGenerationSpecific(void) {}

    private:
      Cell* border;
};

#endif