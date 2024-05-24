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
      /*Serial.print("H: ");
      Serial.println(pixy.ccc.blocks[i].m_height);
      Serial.print("W: ");
      Serial.println(pixy.ccc.blocks[i].m_width);
      delay(10);*/
    }
  }
}

// Take the biggest block (blocks[0]) that's been around for at least 30 frames (1/2 second)
// and return its index, otherwise return -1
int16_t acquireBlock(Pixy2 pixy){

  //pixy.ccc.getBlocks();

  if(pixy.ccc.numBlocks && pixy.ccc.blocks[0].m_age > 30){
    Serial.println("pippo");
    return pixy.ccc.blocks[0].m_index;
  }

  /*if(pixy.ccc.numBlocks){
    return pixy.ccc.blocks[0].m_index;
  }*/

  return -1;
}

//Find the block with the given index taken from acquireBlock
Block *trackBlock(Pixy2 pixy, uint16_t index){

  for(int i = 0; i < pixy.ccc.numBlocks; i++){
    if(pixy.ccc.blocks[i].m_index == index){
      return &pixy.ccc.blocks[i];
    }
  }

  return NULL;
}

void moveMotor(){
  Serial.println("DO THING");
}

void followBlock(Pixy2 pixy){

  //int8_t index = -1;
  Block *block = NULL;
  //long area = 0.0;

  //pixy.ccc.getBlocks();

  //search for a block
  Serial.println("Searching for block...");
  int16_t index = acquireBlock(pixy);
  Serial.print("Index: ");
  Serial.println(index);
  
  //start tracing the block found
  if(index >= 0){
      Serial.println("Block Found!");
      //block = trackBlock(pixy,index);
      for(int i = 0; i < pixy.ccc.numBlocks; i++){
        
        Serial.print("H: ");
        Serial.println(pixy.ccc.blocks[index].m_height);
        Serial.print("W: ");
        Serial.println(pixy.ccc.blocks[index].m_width);
        
        if(pixy.ccc.blocks[i].m_index == index){
          block = &pixy.ccc.blocks[i];
          
        }
      }
      /*Serial.print("H: ");
      Serial.println(block->m_height);
      Serial.print("W: ");
      Serial.println(block->m_width);*/
      /*Serial.print("H: ");
      Serial.println(pixy.ccc.blocks[index].m_height);
      Serial.print("W: ");
      Serial.println(pixy.ccc.blocks[index].m_width);*/

      /*long area = calculateArea(block->m_height, block->m_width);
      Serial.print("Area: ");
      Serial.println(area);*/
      while(1){
        //moveMotor();
        Serial.print("H: ");
        Serial.println(pixy.ccc.blocks[index].m_height);
        Serial.print("W: ");
        Serial.println(pixy.ccc.blocks[index].m_width);
      }
  }

  //if we can track, move the motor else stop the motor and reset the index
  /*if(block){
    moveMotor();
    delay(50);
  }else{
    index = -1;
    motorStop();
    Serial.println("stop");
  }*/
}

long calculateArea(long height, long width){
  return height * width;
}