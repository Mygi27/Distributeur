#ifndef screen_hpp
#define screen_hpp
#include "print.h"

class screen : public Print{
protected: 
  int nbCotes; 
public:
    screen();
    screen(int N);
    ~screen();
};

#endif