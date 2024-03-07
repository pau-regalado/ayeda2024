#include "../include/lattice2D.h"
#include "../include/stateAlive.h"

Lattice2D::Lattice2D(const char* filename, const FactoryCell& f)
  : Lattice(filename, f) { }

void Lattice2D::buildLattice() {
  std::ifstream file("dataFile/" + this->filename);
  // Por ahora es para descartar la primera linea del fichero, dimension
  file >> this->row;

  file >> this->row >> this->col;

  this->lattice.resize(this->row);
  for (int i = 0; i < this->row; i++) {
    this->lattice[i].resize(this->col);
    for (int j = 0; j < this->col; j++) {
      PositionDim<2>* position = new PositionDim<2>(2, i, j);
      StateDead state;
      this->lattice[i][j] = this->cellFactory->createCell(*position, state);
    }
  }

  for (int i = 0; i < this->row; ++i) {
    std::string line;
    file >> line;
    for (int j = 0; j < this->col; ++j) {
      State* state;
      if (line[j] == '0') {
        state = new StateDead();
      } else if (line[j] == '1') {
        state = new StateAlive();                   
      } else {
        throw InvalidCharacterException();
      }
      this->setCell(PositionDim<2>(2, i, j), *(this->cellFactory->createCell(*(new PositionDim<2>(2, i, j)), *state)));
    }
  }
}

Lattice2D::~Lattice2D() { }

void Lattice2D::calculateNextGeneration(void) {
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j]->nextState(*this);  
    }
  }
 
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      this->lattice[i][j]->updateState();
    }
  } 
}

void Lattice2D::saveLatticeDataIntoAFile(std::ofstream& f) {
  f << 2 << std::endl; 
  f << this->row << std::endl;
  f << this->col << std::endl;

  for (int i = 0; i < this->row; ++i) {
    for (int j = 0; j < this->col; ++j) {
      f << lattice[i][j]->getStateInt();
    }
    f << std::endl;
  }
}

std::size_t Lattice2D::getPopulation() const {
  std::size_t  population = 0;
  for (int i = 0; i < this->row; i++) {
    for (int j = 0; j < this->col; j++) {
      population += this->lattice[i][j]->getStateInt();
    }
  }
  return population;
}

std::string Lattice2D::printLattice() {
  std::string s = "";
  for (int i = 0; i < this->col + 2; i++){
    std::cout << "⬛";
  }
  std::cout << std::endl;

  for (int i = 0; i < this->row; i++) {
    std::cout << "⬛";
    for (int j = 0; j < this->col; j++) {
      std::cout << *this->lattice[i][j];
    }
    std::cout << "⬛" << std::endl;
  }
  
  for (int i = 0; i < this->col + 2; i++){
    std::cout << "⬛";
  }
  std::cout << std::endl << std::endl;
  return s;
}
