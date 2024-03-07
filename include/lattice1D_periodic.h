#ifndef _LATTICE1D_PERIODIC_ 
#define _LATTICE1D_PERIODIC_

#include <iostream>
#include "lattice1D.h"

class Lattice1D_periodic: public Lattice1D {
  public:
    Lattice1D_periodic(const char* filename, const FactoryCell& f);
    ~Lattice1D_periodic();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "reflective";}
    void nextGenerationSpecific(void) {}
};

#endif