#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

#include "../include/simulator.h"
#include "../include/latticeFactory.h"
#include "../include/error.h"

int main(int argc, char* argv[]) {
    
  Lattice* lattice;
  LatticeFactory latticeFactory;
  try {
    lattice = latticeFactory.generateLattice(argc, argv);
  } catch (Error& e) {
    std::cerr << "Error: " << e.whats() << std::endl;
    return 1;
  }
  std::cout << "WOOOORRKKSS" << std::endl;
  
  Simulator simulator(lattice);
  try {
    simulator.start();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  
  return 0;
}
