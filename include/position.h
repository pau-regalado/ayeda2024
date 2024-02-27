#ifndef __POSITION__ 
#define __POSITION__

#include <vector>
#include <iostream>

class Position{
  private:
    int x, y;
  
  public:
    Position(int x = 0, int y = 0);
    ~Position(void);

    void setX(const int x);
    int getX(void) const;
    void setY(const int y);
    int getY(void) const;
    Position operator+(Position p);
};

#endif