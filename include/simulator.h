#ifndef __SIMULATOR__ 
#define __SIMULATOR__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

#include "lattice.h"

class Simulator {
  private:
    Lattice* lattice;

  public:
    Simulator(Lattice* lattice);
    ~Simulator();

    void start();

    char showMenuAndAskForOption();
};

#endif