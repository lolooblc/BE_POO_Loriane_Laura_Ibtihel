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

	ExternalDigitalSensorButton ButtonGreenLED(DELAY, "on1.txt");
	ExternalDigitalSensorButton ButtonYellowLED(DELAY,"on2.txt");
	ExternalDigitalSensorButton ButtonRedLED(DELAY,"on3.txt");
	ExternalDigitalSensorButton ButtonBlueLED(DELAY,"on4.txt");

  I2CActuatorScreen screen;
  
  // branchement des capteurs actionneurs
  esp8266.i2c(1,screen);

  esp8266.pin(ledPinGreen,led1);
  esp8266.pin(ledPinYellow,led2);
  esp8266.pin(ledPinRed,led3);
  esp8266.pin(ledPinBlue,led4);

	esp8266.pin(PIN_GREEN_BUTTON,ButtonGreenLED); //PIN_RED_BUTTON
	esp8266.pin(PIN_YELLOW_BUTTON,ButtonYellowLED); //PIN_RED_BUTTON
	esp8266.pin(PIN_RED_BUTTON,ButtonRedLED); //PIN_RED_BUTTON
	esp8266.pin(PIN_BLUE_BUTTON,ButtonBlueLED); //PIN_RED_BUTTON


  // allumage de la carte
  esp8266.run();
  return 0;
}


