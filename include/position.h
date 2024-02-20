#ifndef __POSITION__ 
#define __POSITION__

#include <vector>
#include <iostream>
#include "enum.h"

class Position{
  private:
    int position;
  
  public:
    Position(int position = 0);
    ~Position(void);

    void setPosition(const int position);
    int getPosition(void) const;
};


#endif