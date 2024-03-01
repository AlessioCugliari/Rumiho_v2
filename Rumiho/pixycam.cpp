#include "pixycam.h"

void grabAndPrintBlock(Pixy2 pixy){

  pixy.ccc.getBlocks();

  // If there are detect blocks, print them!
  uint8_t numBlock = pixy.ccc.numBlocks;

  if(numBlock){
    Serial.print("Detected ");
    Serial.println(numBlock);

    for(int i = 0; i < numBlock; i++){
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    }
  }
}