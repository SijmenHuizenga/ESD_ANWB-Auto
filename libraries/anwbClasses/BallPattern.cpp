#include "BallPattern.h"

void BallPattern::draw(LedController control){
  
  for(int i = 0; i < control.getLedAmount(); i++){
    control.setLedOn(i, inverted);
  }
  control.setLedOn(selectedLight, !inverted);
  
  selectedLight += (lTor ? 1 : -1);
  
  if(selectedLight >= control.getLedAmount()){
    selectedLight = control.getLedAmount()-2;
    lTor = false;
  }else if(selectedLight <= 0){
    selectedLight = 0;
    lTor = true;
  }
}

BallPattern::BallPattern(boolean inv){
  inverted = inv;
  selectedLight = 0;
  lTor = true;
}

String BallPattern::getID(){
  return inverted ? "ball inverted" : "ball";
}
