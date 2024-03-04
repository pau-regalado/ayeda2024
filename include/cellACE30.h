#ifndef _CELLACE30_ 
#define _CELLACE30_

#include "../include/cellACE.h"
#include "../include/stateDead.h"

class CellACE30 : public CellACE {
public:
  CellACE30();
  CellACE30(Position* position, State* state);
  ~CellACE30();
};

#endif