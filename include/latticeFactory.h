#ifndef __LATTICEFACTORY__ 
#define __LATTICEFACTORY__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

#include "lattice.h"
#include "cell.h"

enum latticeTypes { OPEN_BORDER, PERIODIC_BORDER, REFLECTIVE_BORDER, NON_BORDERS };
enum cellTypes { ACE_30, ACE_100, LIFE_23_3, LIFE_51_346 };

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