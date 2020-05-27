#include <Arduino.h> 
#include "MySensors.h"


//constructor
Sensors::Sensors(int pin) {
  pinMode(pin,INPUT);
  nbSensors ++;
}

//print the nature of the device
void Sensors::WhoAmI() {
  Serial.print("Je suis un capteur de nature inconnue");
}

//read the sensor's state
int Sensors::GetState() {
  return digitalRead(pin); 
}

int Sensors::nbSensors = 0;

//----------------pushbutton--------------------

//constructor
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int mypin):Sensors(mypin) {
  pin=mypin;  
}

//print the nature of the device
void ExternalDigitalSensorButton::WhoAmI(){
  Serial.print("Je suis un bouton poussoir");
}

int ExternalDigitalSensorButton::GetState(){
  return digitalRead(pin);
}
