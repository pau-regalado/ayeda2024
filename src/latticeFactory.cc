#include "../include/latticeFactory.h"
#include "../include/factoryCell.h"
#include "../include/lattice2D_open.h"
#include "../include/lattice1D_open.h"
// #include "../include/latticePeriodicBorder.h"
// #include "../include/latticeReflectiveBorder.h"
// #include "../include/latticeNonBorders.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"
#include "../include/error.h"

LatticeFactory::LatticeFactory() {}

LatticeFactory::~LatticeFactory() {}

Lattice* LatticeFactory::generateLattice(int argc, char* argv[]) {
  bool rowCheck, colCheck = false;
  bool typeCheck = false;
  bool cellTypeCheck = false;
  bool dimCheck = false;
  int initialCellState = 0;

  int dim = 0, aux = 0;
  std::string filename = "";
  latticeTypes latticeType = latticeTypes::OPEN_BORDER;
  cellTypes cellType = cellTypes::ACE_30;
  
  std::vector<int> dims;

  FactoryCell* factoryCell;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-size") == 0 && i + 1 < argc) {
      if (dimCheck) {
        for (int j = 0; j < dim; j++) {
          aux = std::stoi(argv[i + 1]);
          if (aux > 0) {
            dims.push_back(aux);
            i++;
          } else {
            throw ParsingException();
          }
        }
      } else {
        throw ParsingException();
      }
    } else if (strcmp(argv[i], "-border") == 0 && i + 1 < argc) {
      char* rawBorderType = argv[++i];
      /*if (strcmp(rawBorderType, "periodic") == 0) {
        latticeType = latticeTypes::PERIODIC_BORDER;
        typeCheck = true;
      } else if (strcmp(rawBorderType, "reflective") == 0) {
        latticeType = latticeTypes::REFLECTIVE_BORDER;
        typeCheck = true;
      } else if (strcmp(rawBorderType, "nonborders") == 0) {
        latticeType = latticeTypes::NON_BORDERS;
        typeCheck = true;
      } else */
      if (strcmp(rawBorderType, "open") == 0) {
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
    } else if (strcmp(argv[i], "-dim") == 0 && i + 1 < argc) {
      dim = std::stoi(argv[i + 1]);
      if (dim > 0) {
        dimCheck = true;
      } else {
        throw BadArgumentException();
      }
    } else if (strcmp(argv[i], "-cell") == 0 && i + 1 < argc) {
      char* rawCellType = argv[++i];
      if (strcmp(rawCellType, "Ace30") == 0) {
        factoryCell = new FactoryCellACE30(); 
      } else if (strcmp(rawCellType, "Ace100") == 0) {
        factoryCell = new FactoryCellACE110(); 
      } else if (strcmp(rawCellType, "Life23_3") == 0) {
        factoryCell = new FactoryCellLife23_3(); 
      } else if (strcmp(rawCellType, "Life51_346") == 0) {
        factoryCell = new FactoryCellLife51_346(); 
      }
    }
  }

  if (!filename.empty() || dimCheck && typeCheck) {
    switch (latticeType) {
      /*case latticeTypes::PERIODIC_BORDER: {
        if (!filename.empty()) {
          this->lattice = new LatticePeriodicBorder(filename, );
        } else {
          this->lattice = new LatticePeriodicBorder(row, col);
        }          
        break;
      };
      case latticeTypes::NON_BORDERS: {
        if (!filename.empty()) {
          this->lattice = new LatticeNonBorders(filename);
        } else {
          this->lattice = new LatticeNonBorders(row, col);
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
      };*/
      case latticeTypes::OPEN_BORDER: {
        if (1) {
          this->lattice = new Lattice1D_open(filename.c_str(), *factoryCell, 1);
        } else {
          this->lattice = new Lattice2D_open(filename.c_str(), *factoryCell, 1);
        } 
        break;
      };
    default:
      break;
    }
  } else {
    throw std::exception();
  }
  lattice->buildLattice();
  return lattice;
}

