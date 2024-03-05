#ifndef _LATTICE2D_REFLECTIVE_ 
#define _LATTICE2D_REFLECTIVE_

#include <iostream>
#include "lattice2D.h"

class Lattice2D_reflective: public Lattice2D {
  public:
    Lattice2D_reflective(int row, int col): Lattice2D(){}
    ~Lattice2D_reflective(){}
    Lattice2D_reflective(std::string filename);

    Cell& getCell(Position*);
    const Cell& getCell(Position*) const;
    std::string getName(void){return "Reflective";} 

    void nextGenerationSpecific(void) {}

};

#endif