#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

#include "../include/simulator.h"
#include "../include/latticeFactory.h"

int main(int argc, char* argv[]) {
    
  Lattice* lattice;
  LatticeFactory latticeFactory;
  try {
    lattice = latticeFactory.generateLattice(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  /*
  Simulator simulator(lattice);
  try {
    simulator.start();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }*/
  
  return 0;
}
