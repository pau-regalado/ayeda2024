#ifndef __POSITION__ 
#define __POSITION__

#include <vector>
#include <iostream>
#include "enum.h"

class Position{
  private:
    int x_;
  
  public:
    Position(int x = 0);
    ~Position(void);

    void setX(const int x);
    int getX(void) const;
};


#endif