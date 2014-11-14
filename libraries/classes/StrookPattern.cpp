#include "StrookPattern.h"

void StrookPattern::draw(LedController control){
  if(!keepOn || (selected == 0 && lToR) || 
      (selected >= (control.getLedAmount()/2) &&  !lToR))
    for(int i = 0; i < control.getLedAmount(); i++){
      control.setLedOn(i, false);
    }
  control.setLedOn(selected, true);
  control.setLedOn(control.getLedAmount()-selected-1, true);
  
  selected += lToR ? 1 : -1;
  if(selected > (control.getLedAmount()/2)){
    selected = 0;
  }else if(selected < 0){
    selected = control.getLedAmount()/2;
  }
}

StrookPattern::StrookPattern(boolean leftToRightt, boolean keepon){
  lToR = leftToRightt;
  selected = 0;
  keepOn = keepon;
}

String StrookPattern::getID(){
  String out = "strook ";
  out += lToR ? "in" : "out";
  out += keepOn ? " keepon" : "";
  return out;
}
