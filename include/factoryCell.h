#ifndef _FACTORYCELL_ 
#define _FACTORYCELL_

#include "../include/cellACE110.h"
#include "../include/cellACE30.h"
#include "../include/cellLife23_3.h"
#include "../include/cellLife51_346.h"

class FactoryCell {
  public:
    // Método creador de células
    virtual Cell* createCell(Position& position, State& state) const = 0;
};

class FactoryCellACE110: public FactoryCell {
  public:
    Cell* createCell(Position& p, State& s) const { return new CellACE110(p, s);}
};

class FactoryCellACE30: public FactoryCell {
  public:
    Cell* createCell(Position& p, State& s) const { return new CellACE30(p, s);}
};

class FactoryCellLife23_3: public FactoryCell {
  public:
    Cell* createCell(Position& p, State& s) const { return new CellLife23_3(p, s);}
};

class FactoryCellLife51_346: public FactoryCell {
  public:
    Cell* createCell(Position& p, State& s) const { return new CellLife51_346(p, s);}
};

#endif