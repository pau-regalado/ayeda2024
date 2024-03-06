#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

#include "../include/factoryCell.h"
#include "../include/positionDim.h"

int main(int argc, char* argv[]) {
    
  /*Lattice* lattice;
  LatticeFactory latticeFactory;
  try {
    lattice = latticeFactory.generateLattice(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  Simulator simulator(lattice);
  simulator.start();*/

  FactoryCell* f;
  f = new FactoryCellACE30();

  Cell* c1 = f->createCell(PositionDim<1>(1, {4, 6}), StateDead());

  std::cout << "C1: " << c1 << " " << c1->getPosition()[0]<< std::endl;
  
  return 0;
}
