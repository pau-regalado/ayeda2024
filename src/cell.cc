#include "../include/cell.h"

Cell::Cell() {}

Cell::Cell(Position& position, State& state){
  this->position = position;
  this->state = state; 
  this->nextState_ = nullptr;
}

Cell::~Cell(void){}

const State& Cell::getState(void) const{
  return this->state;
}

const int Cell::getStateValue(void) const{
  return this->state.getState();
}

void Cell::setState(State& state){
  this->state = state;
}

void Cell::setPosition(Position position){
  this->position = position;
}

Position Cell::getPosition(void){
  return this->position;
}

int Cell::nextState(const Lattice& lattice) {
  Cell leftCell = lattice.getCell(this->position.getPosition() - 1);
  Cell rightCell = lattice.getCell(this->position.getPosition() + 1);
  //C(G+1)=(C(G)+R(G)+C(G)*R(G)+L(G)*C(G)*R(G))%2
  int result0 = (this->getStateValue() + rightCell.getStateValue());  
  int result1 = (this->getStateValue() * rightCell.getStateValue());
  int result2 = leftCell.getStateValue() * this->getStateValue() * rightCell.getStateValue();
  int result = (result0 + result1 + result2) % 2;

  this->nextState_ = new State(result);
  return result;
}


int Cell::nextStateMod(const Lattice& lattice) {
  Cell leftCell = lattice.getCell(this->position.getPosition() - 1);
  Cell leftCell2 = lattice.getCell(this->position.getPosition() - 2);
  Cell rightCell = lattice.getCell(this->position.getPosition() + 1);
  Cell rightCell2 = lattice.getCell(this->position.getPosition() + 2);
  //C(G+1)=(C(G)+R(G)+C(G)*R(G)+L(G)*C(G)*R(G))%2
  int result0 = (this->getStateValue() + rightCell2.getStateValue());  
  int result1 = (this->getStateValue() * rightCell2.getStateValue());
  int result2 = leftCell2.getStateValue() * this->getStateValue() * rightCell.getStateValue();
  int result = (result0 + result1 + result2) % 2;
  /*
  int vivas = 0;
  if (this->getStateValue() == 1) { vivas++; }  
  if (leftCell.getStateValue() == 1) { vivas++; }   
  if (leftCell2.getStateValue() == 1) { vivas++; } 
  if (rightCell.getStateValue() == 1) { vivas++; } 
  if (rightCell2.getStateValue() == 1) { vivas++; }

  if (vivas < 3) {} 
  */

  this->nextState_ = new State(result);
  return result;
}

void Cell::updateState() {
  this->state = *this->nextState_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  os << cell.getState();
  return os;
}