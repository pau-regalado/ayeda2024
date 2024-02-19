#ifndef _STATE_ 
#define _STATE_

#include <iostream>
#include "enum.h"

class Rejilla;
class Celula;
class Grid;

// Clase abstracta | todos los metodos son virtuales puros
class State {
  public:
    State();
    int getState();
    void setState(int state);
    int neighbors(const Grid&, int i);
    State* nextState();
};

#endif