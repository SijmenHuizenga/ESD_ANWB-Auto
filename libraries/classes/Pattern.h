#ifndef PATTERN_H
#define PATTERN_H

#include "LedControl.h"

class Pattern{
public:
  virtual void draw(LedController);
  virtual String getID();
};

#endif

