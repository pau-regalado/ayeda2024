#include "../include/cell.h"
#include "../include/stateDead.h"

Cell::Cell(Position& position, State& state){
  // std::cout << "Initializing cell " <<  std::endl;
  this->state = state.clone();
  this->position = position.clone();
  // this->nState = new StateDead();
  // std::cout << "Initialized cell " << this->state->print() << " pos " << this->position->operator[](0) <<  std::endl;
}

Cell::~Cell(void){
  if (this->state != nullptr) {
    delete this->state;
  }
  if (this->nState != nullptr) {
    delete this->nState;
  }
  if (this->position != nullptr) {
    delete this->position;
  }
}

State& Cell::getState(void) const {
  return *(this->state);
}

const int Cell::getStateInt(void) const{
  return this->state->getState();
}

void Cell::setState(State& state){
  this->state = &state;
}

State& Cell::getNextState(void) const{
  return *(this->nState);
}

void Cell::setNextState(State& state){
  this->nState = &state;
}

void Cell::updateState(){
  this->state = this->nState;
}

Position& Cell::getPosition(void) const {
  return *(this->position);
}

void Cell::setPosition(Position& position){
  this->position = &position;
}

std::ostream& Cell::display(std::ostream& os) const {
  return os << this->state->print();
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
  return cell.display(os);
}