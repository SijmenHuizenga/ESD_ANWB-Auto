#ifndef BlockPattern_h
#define BlockPattern_h

#include "Pattern.h"

class BlockPattern : public Pattern{
    private:
      boolean on;
    public:
      BlockPattern();
      void draw(LedController);
      String getID();
};

#endif

