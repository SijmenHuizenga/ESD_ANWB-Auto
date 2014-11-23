#ifndef BallPattern_h
#define BallPattern_h

#include "Pattern.h"

class BallPattern : public Pattern{
    private:
      int selectedLight;
      boolean inverted, lTor;
    public:
      BallPattern(boolean inv);
      void draw(LedController);
      String getID();
};

#endif

