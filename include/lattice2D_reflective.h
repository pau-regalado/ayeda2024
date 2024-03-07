#ifndef _LATTICE2D_REFLECTIVE_ 
#define _LATTICE2D_REFLECTIVE_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_reflective: public Lattice2D {
  public:
    Lattice2D_reflective(const char* filename, const FactoryCell& f);
    ~Lattice2D_reflective();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "reflective";}
    void nextGenerationSpecific(void) {}
};

#endif