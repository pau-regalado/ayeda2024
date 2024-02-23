#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

#include "../include/latticeFactory.h"

int main(int argc, char* argv[]) {
    
  Lattice* lattice;
  LatticeFactory latticeFactory;
  try {
    lattice = latticeFactory.generateLattice(argc, argv);
    lattice->startGeneration();
  } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
  }
  
  return 0;
}
