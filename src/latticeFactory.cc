#include "../include/latticeFactory.h"
#include "../include/latticeOpenBorder.h"
#include "../include/latticePeriodicBorder.h"
#include "../include/latticeReflectiveBorder.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"

LatticeFactory::LatticeFactory() {}

LatticeFactory::~LatticeFactory() {}

Lattice* LatticeFactory::generateLattice(int argc, char* argv[]) {
  bool rowCheck, colCheck = false;
  bool typeCheck = false;
  int initialCellState = 0;
  std::cout << "3" << std::endl;
  int row, col = 0;
  std::string filename = "";
  latticeTypes latticeType = latticeTypes::OPEN_BORDER;
  

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-size") == 0 && i + 1 < argc) {
      row = std::stoi(argv[i + 1]);
      if (row > 0) {
        rowCheck = true;
      }
      i++;
      col = std::stoi(argv[i + 1]);
      if (col > 0) {
        colCheck = true;
      }
      i++;
    } else if (strcmp(argv[i], "-border") == 0 && i + 1 < argc) {
      char* rawBorderType = argv[++i];
      if (strcmp(rawBorderType, "periodic") == 0) {
        latticeType = latticeTypes::PERIODIC_BORDER;
        typeCheck = true;
      } else if (strcmp(rawBorderType, "reflective") == 0) {
        latticeType = latticeTypes::REFLECTIVE_BORDER;
        typeCheck = true;
      } else if (strcmp(rawBorderType, "open") == 0) {
        if ( i + 1 < argc) {
          initialCellState = std::stoi(argv[++i]);
          if (initialCellState == 0 || initialCellState == 1) {
            latticeType = latticeTypes::OPEN_BORDER;
            typeCheck = true;
          }
        }
      }
    } else if (strcmp(argv[i], "-init") == 0 && i + 1 < argc) {
      std::cout << "file" << std::endl;
      filename = argv[++i];
    }
  }

  if (rowCheck && colCheck && typeCheck) {
    switch (latticeType) {
      case latticeTypes::PERIODIC_BORDER: {
        if (!filename.empty()) {
          this->lattice = new LatticePeriodicBorder(filename);
        } else {
          this->lattice = new LatticePeriodicBorder(row, col);
        }          
        break;
      };
      case latticeTypes::REFLECTIVE_BORDER: {
        if (!filename.empty()) {
          this->lattice = new LatticeReflectiveBorder(filename);
        } else {
          this->lattice = new LatticeReflectiveBorder(row, col);
        } 
        break;
      };
      case latticeTypes::OPEN_BORDER: {
        if (!filename.empty()) {
          this->lattice = new LatticeOpenBorder(filename);
        } else {
          this->lattice = new LatticeOpenBorder(row, col, initialCellState);
        } 
        break;
      };
    default:
      break;
    }
  } else {
    throw std::exception();
  }
  return lattice;
}

