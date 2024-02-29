#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

#include "../include/latticeFactory.h"
#include "../include/simulator.h"

int main(int argc, char* argv[]) {
    
  Lattice* lattice;
  LatticeFactory latticeFactory;
  try {
    lattice = latticeFactory.generateLattice(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  Simulator simulator(lattice);
  simulator.start();
  
  return 0;
}
