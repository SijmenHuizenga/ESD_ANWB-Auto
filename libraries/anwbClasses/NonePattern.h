#ifndef NonePattern_h
#define NonePattern_h

#include "Pattern.h"

class NonePattern : public Pattern{
    private:
    public:
      NonePattern();
      void draw(LedController);
      String getID();
};

#endif

