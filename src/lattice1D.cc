#include "../include/cellACE.h"
#include "../include/state.h"
#include "../include/lattice1D.h"
#include "../include/positionDim.h"
#include "../include/stateAlive.h"

Lattice1D::Lattice1D(const char* filename, const FactoryCell& f)
  : Lattice(filename, f) { 
    std::cout << "Construyendo Lattice1D" << std::endl;
  }

void Lattice1D::buildLattice() {
  // Por ahora es para descartar la primera linea del fichero, dimension
  // std::cout << "Voy a leer" << std::endl;
  std::ifstream file("dataFile/" + this->filename);
  file >> this->size;
  // std::cout << "SIZE MALO =  " << this->size << std::endl;

  file >> this->size;
  // std::cout << "SIZE BUENO =  " << this->size << std::endl;
  this->lattice.resize(this->size);
  for (int i = 0; i < this->size; i++) {
    PositionDim<1>* position = new PositionDim<1>(1, i);
    StateDead state;
    this->lattice[i] = this->cellFactory->createCell(*position, state);
  }

  std::string line;
  file >> line;
  // std::cout << "Line " << line << std::endl;

  for (int i = 0; i < size; ++i) {
    State* state;
    if (line[i] == '0') {
      state = new StateDead();
    } else if (line[i] == '1') {
      state = new StateAlive();                   
    } else {
      throw InvalidCharacterException();
    }
    // std::cout << "Creo cell en " << i << " Estado " << line[i] << std::endl;
    PositionDim<1>* pos = new PositionDim<1>(1, i);
    // std::cout << "posicion CREADA" << std::endl;
    Cell* c = this->cellFactory->createCell(*pos, *state);
    // std::cout << "CELULA CREADA" << std::endl;
    this->setCell(*pos, *c);
    //std::cout << "CELULA GUARDADA" << std::endl;
  }
}

Lattice1D::~Lattice1D() {
  std::cout << "Destruccion Lattice1D" << std::endl;
}

void Lattice1D::calculateNextGeneration(void) {
  for (int i = 0; i < this->size; i++) {
    // this->lattice[i]->setPosition(PositionDim<1>(1, i));  
    this->lattice[i]->nextState(*this);  
  }
 
  for (int i = 0; i < this->size; i++) {
    this->lattice[i]->updateState();
  }
}

std::size_t Lattice1D::getPopulation() const {
  std::size_t population = 0;
  for (int i = 0; i < this->size; i++) {
      population += this->lattice[i]->getStateInt();
  }
  return population;
}

std::string Lattice1D::printLattice() {
  std::cout << "⬛";
  for (int i = 0; i < this->size; i++) { 
    std::cout << *this->lattice[i];
  }
  std::cout << "⬛" << std::endl;
  return "";
}

void Lattice1D::saveLatticeDataIntoAFile(std::ofstream& f) {
  f << this->size << std::endl; 
  for (int i = 0; i < this->size; i++) {
    f << this->lattice[i]->getStateInt();
  }
}