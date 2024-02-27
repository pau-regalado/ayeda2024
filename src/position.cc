#include "../include/position.h"


Position::Position(int x, int y){
  this->x = x;
  this->y = y;
}

Position::~Position(void){}

void Position::setX(const int x) { this->x = x; }

int Position::getX(void) const{ return this->x;}

void Position::setY(const int y) { this->y = y; }

int Position::getY(void) const{ return this->y;}

Position Position::operator+(Position p) {
  return Position(this->getX() + p.getX(), this->getY() + p.getY());
}

