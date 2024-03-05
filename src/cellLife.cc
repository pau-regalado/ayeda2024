#include "../include/cellLife.h"
#include "../include/stateDead.h"
#include "../include/stateAlive.h"

CellLife::CellLife() {
  this->position = new PositionDim<>();
  this->state = new StateDead();
}

CellLife::CellLife(Position* position, State* state) {
  this->position = position;
  this->state = state; 
}

CellLife::~CellLife() {}

int CellLife::nextState(Lattice& lattice) {
    // nextState implementation
}

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

int Cell::nextState(Lattice& lattice) {
  this->nState = this->state->nextState(this->countAliveNeighbours(lattice));
  return 0;
}

void Cell::updateState() {
  this->state = this->nState;
}

int Cell::countAliveNeighbours(Lattice& lattice) {
  int alives = 0;
  /*
  for (Position offset: neighbours ) {
    alives += lattice.getCell(new Position(*(this->position) + offset)).getStateInt();
  }*/
  for (int i = 0; i < neighbours.size(); i++ ) {
    alives += lattice.getCell(new Position(*(this->position) + neighbours[i])).getStateInt();
  }
  return alives;
}

State* Cell::nextStateS(int vivas){
  if ((vivas == 2) || (vivas == 3)){
      return new StateAlive();
  } else {
      return new StateDead();
  }
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}
