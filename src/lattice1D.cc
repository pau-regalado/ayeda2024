#include "../include/cellACE.h"
#include "../include/state.h"
#include "../include/lattice1D.h"
#include "../include/positionDim.h"
#include "../include/stateAlive.h"

Lattice1D::Lattice1D(const char* filename, const FactoryCell& f)
  : Lattice(filename, f) { }

void Lattice1D::buildLattice(std::ifstream& file) {
  // Por ahora es para descartar la primera linea del fichero, dimension
  file >> this->size;

  file >> this->size;

  this->lattice.resize(this->size);
  // for (int i = 0; i < this->size; i++) {
  //   this->lattice[i].setPosition(new PositionDim<1>(i));
  // }

  std::string line;
  file >> line;

  for (int i = 0; i < size; ++i) {
    State* state;
    if (line[i] == '0') {
      state = new StateDead();
    } else if (line[i] == '1') {
      state = new StateAlive();                   
    } else {
      throw InvalidCharacterException();
    }
    this->setCell(PositionDim<1>(1, i), *(this->cellFactory->createCell(PositionDim<1>(1, i), *state)));
  }
}


Lattice1D::~Lattice1D() {
  std::cout << "Destruccion Lattice1D" << std::endl;
}

void Lattice1D::calculateNextGeneration(void) {
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].nextState(*this);  
  }
 
  for (int i = 0; i < this->size; i++) {
    this->lattice[i].updateState();
  }
}

std::size_t Lattice1D::getPopulation() const {
  std::size_t population = 0;
  for (int i = 0; i < this->size; i++) {
      population += this->lattice[i].getStateInt();
  }
  return population;
}

std::string Lattice1D::printLattice() {
  std::cout << "⬛";
  for (int i = 0; i < this->size; i++) { 
    std::cout << this->lattice[i];
  }
  std::cout << "⬛" << std::endl;
  return "";
}

void Lattice1D::saveLatticeDataIntoAFile(std::ofstream& f) {
  f << this->size << std::endl; 
  for (int i = 0; i < this->size; i++) {
    f << this->lattice[i].getStateInt();
  }
}