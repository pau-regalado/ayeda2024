#include "../include/cellACE.h"
#include "../include/stateDead.h"

CellACE::CellACE(const PositionDim<1>& position, const State& state) : Cell(state) {
  *(this->position) = position;
}

CellACE::~CellACE() {}

int CellACE::nextState(Lattice& lattice) {
    // nextState implementation
}

void CellACE::updateState() {
  
}

/*
const State& Cell::getState(void) const{
  return *(this->state);
}

const int Cell::getStateInt(void) const{
  return this->state->getState();
}

void Cell::setState(State& state){
  this->state = &state;
}

void Cell::setPosition(Position* position){
  this->position = position;
}

Position Cell::getPosition(void){
  return *(this->position);
}

int Cell::nextState(Lattice& lattice) {
  this->nState = this->state->nextState(this->countAliveNeighbours(lattice));
  return 0;
}

void Cell::updateState() {
  this->state = this->nState;
}

int Cell::countAliveNeighbours(Lattice& lattice) {
  int alives = 0;

  for (int i = 0; i < neighbours.size(); i++ ) {
    alives += lattice.getCell(new Position(*(this->position) + neighbours[i])).getStateInt();
  }
  return alives;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}*/
