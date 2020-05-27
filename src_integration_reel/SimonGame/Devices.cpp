#include <Arduino.h> 
#include "Devices.h"

//constructor
Devices::Devices(){
	nbDevices++;
}

//print the nature of the device
void Devices::WhoAmI(){
	Serial.print("Je suis un composant de nature inconnue");
}

int Devices::nbDevices = 0;
