#ifndef _LATTICE1D_ 
#define _LATTICE1D_

#include <iostream>
#include "lattice.h"

class Lattice1D: public Lattice {
  public:
    Lattice1D(): Lattice(1){}
    ~Lattice1D(){}

};

#endif