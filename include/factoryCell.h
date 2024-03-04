#ifndef _FACTORYCELL_ 
#define _FACTORYCELL_

#include "../include/cellLife.h"
#include "../include/stateDead.h"

class FactoryCell {
public:
// Método creador de células
virtual Cell* createCell(const Position&, const State&)
const=0;
};

#endif