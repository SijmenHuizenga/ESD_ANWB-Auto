#include "LinePattern.h"

void LinePattern::draw(LedController control){
  for(int i = 0; i <= selected; i++){
    control.setLedOn(lToR ? i : control.getLedAmount() - i-1, true);
  }
  for(int i = selected+1; i < control.getLedAmount(); i++){
    control.setLedOn(lToR ? i : control.getLedAmount() - i-1, false);
  }
  
  selected ++;
  if(selected >= control.getLedAmount()){
    selected = -1;
  }
}

LinePattern::LinePattern(boolean leftToRightt){
  lToR = leftToRightt;
  selected = 0;
}

String LinePattern::getID(){
  return lToR ? "line lr" : "line rl";
}
