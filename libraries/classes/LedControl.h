#ifndef LedControl_h
#define LedControl_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class LedController{
    private:
      int pins[9];
    public:
      LedController();
      void initilize();
      void setLedOn(int, boolean);
      void resetLights();
      int getLedAmount();		
      String getCurState();
};

#endif
