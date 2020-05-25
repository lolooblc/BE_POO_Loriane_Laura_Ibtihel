#include <fstream>
#include "mydevices.h"

using namespace std;

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      cout << "((((eteint))))\n";
		}
    else {
    	cout << "((((allume))))\n";
		}
    sleep(temps);
	}
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}


//classe ExternalDigitalSensorButton

//constructeur :
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t):Device(),button_state(LOW),temps(t){ 
} //initialement le bouton est relaché



int ExternalDigitalSensorButton::updateState() {
  if(ifstream("on.txt")){ //le fichier existe et l'état passe du bouton passe "on"
    button_state=1;
  }
  else
    button_state=0;
  return button_state;
}  

void ExternalDigitalSensorButton::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem=updateState();
    if (button_state)
      cout << "((((bouton enfoncé))))\n";
    else
      cout << "((((bouton relaché))))\n";
    sleep(temps);
  }
}


