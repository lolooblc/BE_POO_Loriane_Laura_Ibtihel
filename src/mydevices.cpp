#include <fstream>
#include "mydevices.h"

using namespace std;

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t, string nomLed):Device(),state(LOW),temps(t){
	nomLeds = nomLed;
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      cout <<"(((( " <<nomLeds <<" eteint))))\n";
		}
    else {
    	cout <<"(((( " <<nomLeds <<" allume))))\n";
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
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t, string texte):Device(),button_state(LOW),temps(t){
	textes = texte;
} //initialement le bouton est relaché



int ExternalDigitalSensorButton::updateState() {
  if(ifstream(textes)){ //le fichier existe et l'état passe du bouton passe "on"
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
    if (button_state){
      cout << "((((bouton enfoncé))))\n";

		}
    else
      cout << "((((bouton relaché))))\n";
    sleep(temps);
  }
}


AnalogActuatorBuzzer::AnalogActuatorBuzzer(double f, int t):Device(),delay_value(f),beeplong(t){
}

int AnalogActuatorBuzzer::writeError() {
int test_error = 0;
  if(ifstream("error.txt")){ // si le fichier d'erreur existe et l'état passe vers "on"
    test_error = 1;
    remove("error.txt");
  }
  return test_error;
}

void AnalogActuatorBuzzer::run(){
    int test_error = 0;

    while(test_error==0){
    if(ptrmem!=NULL)
    *ptrmem=writeError();
    if (test_error==1)
    {
    cerr<<"Le buzzeur vibre : mauvaise sequence"<<endl;
    test_error=0;
    }

    }

}
