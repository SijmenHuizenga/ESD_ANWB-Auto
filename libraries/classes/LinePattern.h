#ifndef LinePattern_h
#define LinePattern_h

#include "Pattern.h"

class LinePattern : public Pattern{
    private:
      boolean lToR;
      int selected;
    public:
      LinePattern(boolean);
      void draw(LedController);
      String getID();
};

#endif

