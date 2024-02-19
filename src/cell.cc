#include "../include/cell.h"
#include "../include/state.h"


Cell::Cell() {

}

Cell::Cell(Position& position ,State* estado){
  position_ = position;
  vecinas_.resize(2);

  if (estado == nullptr){
    estado_ = new StateDead(this);
  } else {
    estado_ = estado;
  }
}

Cell::~Cell(void){
  delete estado_;
}

void Cell::clearVecinas(void){
  for (int i = 0; i < vecinas_.size(); i++)
    vecinas_[i] = 0;
}

State const * Cell::getState(void) const{
  return estado_;
}

std::vector<int>& Cell::getVecinas(void){
  return vecinas_;
}

void Cell::setState(State* estado){
  delete estado_;
  estado_ = estado;
}

Position Cell::getPosition(void){
  return position_;
}

int Cell::getVivas(void){
  return 0;
}

void Cell::updateState(void){
  // Cambia su estado por el que dicte su objeto estado
  estado_ = estado_->nextState();
}

/**
 * void Cell::neighbors(const Grid& g){
  estado_->neighbors(g, position_);
}
*/


std::ostream& operator<<(std::ostream& os, const Cell& cell){
  switch (cell.getState()->getState())
  {
  case A:
      return os << "🔵";
    break;
  case D:
      return os << "🔴";
    break;
  }
}