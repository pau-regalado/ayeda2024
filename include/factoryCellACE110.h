#ifndef _FACTORYCELL_ 
#define _FACTORYCELL_

#include "../include/cellACE100.h"
#include "../include/stateDead.h"
#include "../include/factoryCell.h"

class FactoryCellAce100: public FactoryCell {
public:
Cell* createCell(const Position& p,const State& s) const
{
return new CellAce100(p, s);
}
};

#endif