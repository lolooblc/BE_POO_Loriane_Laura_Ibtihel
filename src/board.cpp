#include "core_simulation.h"
#include "mydevices.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
	DigitalActuatorLED led1(DELAY, "led verte");
	DigitalActuatorLED led2(DELAY, "led jaune");
	DigitalActuatorLED led3(DELAY, "led rouge");
	DigitalActuatorLED led4(DELAY, "led bleue");

	ExternalDigitalSensorButton ButtonGreenLED(DELAY, "bouttonVert.txt");
	ExternalDigitalSensorButton ButtonYellowLED(DELAY,"bouttonJaune.txt");
	ExternalDigitalSensorButton ButtonRedLED(DELAY,"bouttonRouge.txt");
	ExternalDigitalSensorButton ButtonBlueLED(DELAY,"bouttonBleu.txt");
	ExternalDigitalSensorButton ButtonMENU(DELAY,"bouttonMenu.txt");

	AnalogActuatorBuzzer buzzer(DELAY,BEEP);

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

	esp8266.pin(buttonPinMenu,ButtonMENU); //PIN_MENU

    esp8266.pin(pinBuzzer,buzzer); //PIN_BUZZER

  // allumage de la carte
  esp8266.run();
  return 0;
}






