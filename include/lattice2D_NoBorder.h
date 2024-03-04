#ifndef _LATTICE2D_NOBORDER_ 
#define _LATTICE2D_NOBORDER_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_NoBorder: public Lattice2D {
  public:
    Lattice2D_NoBorder(): Lattice2D(){}
    ~Lattice2D_NoBorder(){}

};

#endif