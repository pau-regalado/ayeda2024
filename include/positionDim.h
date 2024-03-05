#ifndef _POSITIONDIM_ 
#define _POSITIONDIM_

#include "../include/position.h"
#include "../include/error.h"
#include <stdarg.h>

template <int Dim=2, class Coordinate_t=int>
class PositionDim: public Position {
  private:
    Coordinate_t Coordinates[Dim];
  public:
    PositionDim(int sz, ...) {
      if(sz != Dim) {
        throw Ac_Exception;
      }
      va_list vl;
      va_start(vl, sz);
      for(int d=0; d<Dim; d++) {       
        Coordinates[d] = va_arg(vl, Coordinate_t);
      }
      va_end(vl);
    }
    
    Coor_t operator[](unsigned int i) const {
      if (i >= Dim) {
        throw Ac_Exception();
      }
      return this->Coordinates[i];
    }
};
#endif