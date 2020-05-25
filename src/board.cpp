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

	ExternalDigitalSensorButton ButtonGreenLED(DELAY);
	ExternalDigitalSensorButton ButtonYellowLED(DELAY);
	ExternalDigitalSensorButton ButtonRedLED(DELAY);
	ExternalDigitalSensorButton ButtonBlueLED(DELAY);


#define PIN_GREEN_BUTTON 5 // broche bouton poussoire led verte
#define PIN_YELLOW_BUTTON 6 // broche bouton poussoire led jaune
#define PIN_RED_BUTTON 7 // broche bouton poussoire led rouge
#define PIN_BLUE_BUTTON 8 // broche bouton poussoire led blue

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


