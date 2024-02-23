#include "../include/latticeFactory.h"
#include "../include/latticeOpenBorder.h"
#include "../include/latticePeriodicBorder.h"
#include "../include/latticeReflectiveBorder.h"

LatticeFactory::LatticeFactory() {}

LatticeFactory::~LatticeFactory() {}

Lattice* LatticeFactory::generateLattice(int argc, char* argv[]) {
  bool sizeCheck = false;
  bool typeCheck = false;
  int initialCellState = 0;

  int size = 0;
  std::string filename = "";
  latticeTypes latticeType = latticeTypes::OPEN_BORDER;

  for (int i = 1; i < argc; ++i) {
    //std::cout << "Input : " << argv[i] << std::endl;
    if (strcmp(argv[i], "-size") == 0 && i + 1 < argc) {
      size = std::stoi(argv[i + 1]);
      if (size > 0) {
        sizeCheck = true;
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

  if (sizeCheck && typeCheck) {
    switch (latticeType) {
      case latticeTypes::PERIODIC_BORDER: {
        this->lattice = new LatticePeriodicBorder(size);
        break;
      };
      case latticeTypes::REFLECTIVE_BORDER: {
        this->lattice = new LatticeReflectiveBorder(size);
        break;
      };
      case latticeTypes::OPEN_BORDER: {
        this->lattice = new LatticeOpenBorder(size, initialCellState);
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

    int size;
    file >> size;

    std::string line;
    file >> line;

    for (int i = 0; i < size; ++i) {
      if (line[i] == '0' || line[i] == '1') {
          State state(line[i] - '0'); // Convertir el carácter a entero
          Position position(i);
          Cell cell(position, state);
          this->lattice->setCell(position, cell);
      } else {
          throw std::runtime_error("El archivo contiene datos no válidos.");
      }
    }
}