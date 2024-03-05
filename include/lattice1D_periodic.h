#ifndef __LATTICE1D_PERIODIC__ 
#define __LATTICE1D_PERIODIC__

#include "../include/lattice1D.h"
#include "../include/cell.h"

class Lattice1D_periodic: public Lattice1D {
  public:
    Lattice1D_periodic(int size): Lattice1D(){}
    ~Lattice1D_periodic(){}

    Cell& getCell(int position);
    const Cell& getCell(int position) const;
    std::string getName(void){return "Periodic";}

};

#endif