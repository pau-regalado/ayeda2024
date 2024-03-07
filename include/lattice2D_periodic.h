#ifndef _LATTICE2D_PERIODIC_ 
#define _LATTICE2D_PERIODIC_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_periodic: public Lattice2D {
  public:
    Lattice2D_periodic(const char* filename, const FactoryCell& f);
    ~Lattice2D_periodic();

    Cell& getCell(const Position& p);
    const Cell& getCell(const Position& p) const;
    std::string getName(void){return "periodic";}
    void nextGenerationSpecific(void) {}

    private:
      Cell* border;
};

#endif