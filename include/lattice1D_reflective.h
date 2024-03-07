#ifndef _LATTICE1D_REFLECTIVE_ 
#define _LATTICE1D_REFLECTIVE_

#include <iostream>
#include "lattice1D.h"

class Lattice1D_reflective: public Lattice1D {
  public:
    Lattice1D_reflective(const char* filename, const FactoryCell& f);
    ~Lattice1D_reflective();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "reflective";}
    void nextGenerationSpecific(void) {}
};

#endif