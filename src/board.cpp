#include "core_simulation.h"
#include "mydevices.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
  DigitalActuatorLED led1(DELAY); 
  DigitalActuatorLED led2(DELAY); 
  DigitalActuatorLED led3(DELAY); 
  DigitalActuatorLED led4(DELAY); 
  I2CActuatorScreen screen;
  
  // branchement des capteurs actionneurs
  esp8266.i2c(1,screen);

  esp8266.pin(0,led1);
  esp8266.pin(1,led2);
  esp8266.pin(2,led3);
  esp8266.pin(3,led4);


  // allumage de la carte
  esp8266.run();
  return 0;
}


