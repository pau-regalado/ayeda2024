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
    Simulator simulator(lattice);
    simulator.start();

  } catch (Error& e) {
    std::cerr << "Error: " << e.whats() << std::endl;
    return 1;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  
  return 0;
}
