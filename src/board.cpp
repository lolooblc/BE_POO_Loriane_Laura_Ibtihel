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
  ExternalDigitalSensorButton ButtonRedLED(DELAY);
  I2CActuatorScreen screen;
  AnalogActuatorBuzzer buzzer(FREQ,DELAY);

  // branchement des capteurs actionneurs
  esp8266.i2c(1,screen);

  esp8266.pin(ledStatePinGreen,led1);
  esp8266.pin(ledStatePinYellow,led2);
  esp8266.pin(ledStatePinRed,led3);
  esp8266.pin(ledStatePinBlue,led4);

  esp8266.pin(4,ButtonRedLED); //PIN_RED_BUTTON

  esp8266.pin(pinBuzzer,buzzer);


  // allumage de la carte
  esp8266.run();
  return 0;
}







