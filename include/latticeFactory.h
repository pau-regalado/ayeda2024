#ifndef __LATTICEFACTORY__ 
#define __LATTICEFACTORY__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

#include "lattice.h"
#include "cell.h"

enum latticeTypes { OPEN_BORDER, PERIODIC_BORDER, REFLECTIVE_BORDER };

class LatticeFactory {
  private:
    Lattice* lattice;

  public:
    LatticeFactory();
    ~LatticeFactory();

    Lattice* generateLattice(int argc, char* argv[]);
    void buildLatticeFromFile(std::string filename);
};

#endif