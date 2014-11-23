#include "BlockPattern.h"

void BlockPattern::draw(LedController control){
  on = !on;
  for(int i = 0; i < control.getLedAmount(); i++){
    control.setLedOn(i, on);
  }
}

BlockPattern::BlockPattern(){
  on = true;
}

String BlockPattern::getID(){
  return "block";
}
