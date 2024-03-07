#ifndef __POSITION__ 
#define __POSITION__

#include <vector>
#include <iostream>

typedef int Coor_t;
class Position {
public:
  // Operador de acceso a la i-ésima coordenada
  virtual Coor_t operator[](unsigned int) const = 0;
  ~Position() {std::cout << "BORRO POSITION" << std::endl;}
  virtual Position* clone() const = 0;
};

#endif

