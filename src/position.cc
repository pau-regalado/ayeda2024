#include "../include/position.h"


Position::Position(int x){
  x_ = x;
}

Position::~Position(void){}

void Position::setX(const int x){
  x_ = x;
}

int Position::getX(void) const{
  return x_;
}

