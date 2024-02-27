#include "../include/cell.h"
#include "../include/stateDead.h"

Cell::Cell() {
  this->position = position;
  this->state = new StateDead();
}

Cell::Cell(Position& position, State* state){
  this->position = position;
  this->state = state; 
}

Cell::~Cell(void){}

const State& Cell::getState(void) const{
  return *(this->state);
}

const int Cell::getStateInt(void) const{
  return this->state->getState();
}

void Cell::setState(State& state){
  this->state = &state;
}

void Cell::setPosition(Position position){
  this->position = position;
}

Position Cell::getPosition(void){
  return this->position;
}

int Cell::nextState(const Lattice& lattice) {
  this->nState = this->state->nextState(this->countAliveNeighbours(lattice));
  return 0;
}

void Cell::updateState() {
  this->state = this->nState;
}

int Cell::countAliveNeighbours(const Lattice& lattice) {
  int alives = 0;
  for (Position p: neighbours ) {
    alives += lattice.getCell(this->position + p).getStateInt();
  }
  //std::cout << "i was here 1" << std::endl;
  return alives;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}