#include <fstream>
#include "mydevices.h"

using namespace std;

///////////////////////Classe Actuator //////////////////////////////////
Actuator :: Actuator () : Device(){}
void Actuator::run(){}


//////////////// classe DigitalActuatorLED /////////////////////////////
DigitalActuatorLED::DigitalActuatorLED(int t, string nomLed):Actuator(),state(LOW){
	temps = t;
	nomLeds = nomLed;
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      //cout <<"(((( " <<nomLeds <<" eteint))))\n"; //afiche en permanence l'état des LED
		}
    else {
    	//cout <<"(((( " <<nomLeds <<" allume))))\n"; //affiche en permanence l'état des LED
		}
    sleep(temps);
	}
}

///////////////// classe I2CActuatorScreen /////////////////////////////
I2CActuatorScreen::I2CActuatorScreen ():Actuator(){
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

/////////////// classe AnalogActuatorBuzzer /////////////////////////////
AnalogActuatorBuzzer::AnalogActuatorBuzzer(double f, int t):Actuator(),delay_value(f),beeplong(t){
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

////////////////////////// Classe sensor /////////////////////////////////// 
//constructeur 
Sensor :: Sensor () : Device(){}
void Sensor::run(){}


/////////////// classe ExternalDigitalSensorButton //////////////////////////////
//constructeur :
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t, string texte):Sensor(),button_state(LOW){
	temps = t;
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

//fonction run
void ExternalDigitalSensorButton::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem=updateState();
    if (button_state){
			if(ifstream("bouttonVert.txt")){
				cout << "((((bouton vert enfoncé))))\n";
			}
			else if (ifstream("bouttonJaune.txt")){
				cout << "((((bouton jaune enfoncé))))\n";
			}
			else if (ifstream("bouttonRouge.txt")){
				cout << "((((bouton rouge enfoncé))))\n";
			}
			else if (ifstream("bouttonBleu.txt")){
				cout << "((((bouton bleu enfoncé))))\n";
			}
			else {
				cout << "((((bouton menu enfoncé))))\n";
			}

		}
    sleep(temps);
  }
}



