#ifndef _LATTICE2D_ 
#define _LATTICE2D_

#include <iostream>
#include "lattice.h"

class Lattice2D: public Lattice {
  public:
    Lattice2D(): Lattice(1){}
    ~Lattice2D(){}

};

#endif