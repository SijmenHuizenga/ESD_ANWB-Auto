#include "NonePattern.h"

void NonePattern::draw(LedController control){
  for(int i = 0; i < control.getLedAmount(); i++){
    control.setLedOn(i, false);
  }
}

NonePattern::NonePattern(){}

String NonePattern::getID(){
  return "off";
}
