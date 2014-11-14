#ifndef StrookPattern_h
#define StrookPattern_h

#include "Pattern.h"

class StrookPattern : public Pattern{
    private:
      boolean lToR;
      boolean keepOn;
      int selected;
    public:
      StrookPattern(boolean, boolean);
      void draw(LedController);
      String getID();
};

#endif

