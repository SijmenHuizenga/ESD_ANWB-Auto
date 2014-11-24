#include "LedControl.h"
#include "BlockPattern.h"
#include "BallPattern.h"
#include "NonePattern.h"
#include "StrookPattern.h"
#include "LinePattern.h"
#include "LedControl.h"

LedController controller;

String inputLine = "";

unsigned long milliStart = 0;
const int patternAmount = 10;
int selectedPattern = 1;
int sleeptime = 50;

Pattern *patterns[patternAmount];

void setup(){
  Serial.begin(9600);
  controller = LedController();
  controller.initilize();
  resetPatterns();
}

void resetPatterns(){
  patterns[0] = new BlockPattern();
  patterns[1] = new BallPattern(true);
  patterns[2] = new BallPattern(false);
  patterns[3] = new NonePattern();
  patterns[4] = new StrookPattern(true, true);
  patterns[5] = new StrookPattern(true, false);
  patterns[6] = new StrookPattern(false, true);
  patterns[7] = new StrookPattern(false, false);
  patterns[8] = new LinePattern(true);
  patterns[9] = new LinePattern(false);
}

void loop(){
  if(millis()-milliStart >= sleeptime){
    patterns[selectedPattern]->draw(controller);
    milliStart = millis();
  }
  if(Serial.available() > 0){
      int in = Serial.read();
      if(in == '\n'){
        Serial.println(handleCommand(inputLine));
        inputLine = "";
      }else{
        inputLine += String(char(in));
      }
  }
}

String handleCommand(String command){
  if(command.startsWith("speed")){
    int newTime = command.substring(6).toInt();
    if(newTime <=0){
      return "Speed can not be smaller than 0.";
    }
    sleeptime = newTime;
    return "Speed updated to " + String(sleeptime) + ".";
  }
  if(command.startsWith("shape")){
    String shape = command.substring(6);
    for(int i = 0; i < patternAmount; i++){
        if(shape.startsWith(patterns[i]->getID())){
            selectedPattern = i;
            return "The pattern is updated to " + patterns[i]->getID() + "."; 
        }
    }
    return "No shape with the name " + shape + " could be found.";
  }
  if(command.startsWith("help")){
      Serial.println("=============================");
      Serial.println("Available commands:");
      Serial.println("speed [int] - set speed of the pattern");
      Serial.println("shape [shape name] - set the shape of the pattern. Avalable patterns:");
      for(int i = 0; i < patternAmount; i++){
          Serial.println("  + " + patterns[i]->getID());
      }
      Serial.println("printGraphData - prints all possible patterns in console.");
      return "=============================";
  }
  if(command.startsWith("printGraphData")){
    Serial.println("=============================");
    resetPatterns();
    for(int i = 0; i < patternAmount; i++){
      controller.resetLights();
      Serial.println(patterns[i]->getID());
      for(int j = 0; j < 2*controller.getLedAmount(); j++){
        patterns[i]->draw(controller);
        Serial.println(controller.getCurState());
        //delay(1);
      }
    }
    return "=============================";
  }
  return "This command could not be found. Please use the command 'help' to receive a list of avalable commands.";
}
