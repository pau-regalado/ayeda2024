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
      filename = argv[++i];
    }
  }

  if (rowCheck && colCheck && typeCheck) {
    switch (latticeType) {
      case latticeTypes::PERIODIC_BORDER: {
        std::cout << "Periodic: " << std::endl;
        this->lattice = new LatticePeriodicBorder(row, col);
        break;
      };
      case latticeTypes::REFLECTIVE_BORDER: {
        this->lattice = new LatticeReflectiveBorder(row, col);
        break;
      };
      case latticeTypes::OPEN_BORDER: {
        this->lattice = new LatticeOpenBorder(row, col, initialCellState);
        break;
      };
    default:
      break;
    }
  } else {
    throw std::exception();
  }

  if (!filename.empty()) {
    buildLatticeFromFile(filename);
  }
  return lattice;
}

void LatticeFactory::buildLatticeFromFile(std::string filename) {
  std::ifstream file("dataFile/" + filename);
    if (!file.is_open()) {
      throw std::runtime_error("Error al abrir el archivo.");
    }

    int row;
    file >> row;
    int col;
    file >> col;

    std::string line;
    file >> line;

    for (int i = 0; i < row; ++i) {
      for (int i = 0; i < col; ++i) {
        if (line[i] == '0') {
            State* state = new StateDead(); 
            Position position(i);
            Cell cell(position, state);
            this->lattice->setCell(position, cell);
        } else if (line[i] == '1') {
            State* state = new StateAlive(); 
            Position position(i);
            Cell cell(position, state);
        } else {
            throw std::runtime_error("El archivo contiene datos no válidos.");
        }
      }
    }
}