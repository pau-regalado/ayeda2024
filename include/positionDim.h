#ifndef _POSITIONDIM_ 
#define _POSITIONDIM_

#include "position.h"
#include "error.h"
#include <stdarg.h>

template <int Dim=2, class Coordinate_t=int>
class PositionDim: public Position {
  private:
    Coordinate_t Coordinates[Dim];
  public:
    PositionDim(int sz, ...) {
      std::cout << "En position sz = " << sz << std::endl;
      va_list vl;
      va_start(vl, sz);
      for(int d = 0; d < sz; d++) {       
        Coordinates[d] = va_arg(vl, Coordinate_t);
      }
      va_end(vl);
      // std::cout << "En position | Sali del for" << std::endl;
    }
    
    Coor_t operator[](unsigned int i) const {
      // if (i >= Dim) {
      //   throw Ac_Exception();
      // }
      // std::cout << "COJO LO DE LA POS " << i << std::endl;
      std::cout << "TAAMAÑO COORD " << this->Coordinates[i] << std::endl;
      return this->Coordinates[i];
    }

    PositionDim<Dim, Coordinate_t>* clone() const override {
      return new PositionDim<Dim, Coordinate_t>(*this);
    }

/*
    PositionDim(const PositionDim& other) {
      std::cout << "En constructor de copia                                   EEEEEEEEEEEE" << std::endl;
      for (int i = 0; i < Dim; i++) {
        Coordinates[i] = other.Coordinates[i];
      }
    }

    PositionDim& operator=(const PositionDim& other) {
      std::cout << "En operador de asignación                                   AAAAAAAAaa" << std::endl;
      if (this != &other) { // Verifica si no estás asignando el mismo objeto
        for (int i = 0; i < Dim; i++) {
          Coordinates[i] = other.Coordinates[i];
        }
      }
      return *this;
    }*/
};

#endif