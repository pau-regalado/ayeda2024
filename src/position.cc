#include "../include/position.h"


Position::Position(int position){
  this->position = position;
}

Position::~Position(void){}

void Position::setPosition(const int position){
  this->position = position;
}

int Position::getPosition(void) const{
  return this->position;
}

