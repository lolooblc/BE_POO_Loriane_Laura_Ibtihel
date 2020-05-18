
#include "mydevices.h"

using namespace std;

//variable globale luminosite environnement
static volatile int lumiosite_environnement = 200;

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){
  alea=1;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
		int state_prev = state;
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      cout << "((((eteint))))\n";
			if (state_prev!=state){
				lumiosite_environnement-=50;
			}
		}
    else {
    	cout << "((((allume))))\n";
			if (state_prev!=state){
					lumiosite_environnement+=50;
			}
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

//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int t):Device(),temps(t){
  alea=1;
}

void AnalogSensorLuminosity::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=lumiosite_environnement+alea;
    sleep(temps);
  }
}


////////////// JEU /////////////////////////////////////

#define MAXARRAY 10 // définir la longeur de la sequence
int ledPin[] ={2,3,4,5}; // Tableau de led avec numéros de broche
#define   piezoPin 13 // Broche piézo
#define buttonPinRed 6 // broche bouton poussoire led rouge
#define buttonPinGreen 7 // broche bouton poussoire vert
#define buttonPinYellow 8 // broche bouton poussoire led jaune
#define bouttonPinWhite 9 // broche bouton poussoire led blanche
#define ledStatePinGreen 10 // led d' etat verte
#define ledStatePinYellow 11 // led d' etat jaune
#define ledStatePinRed 12 // led d' etat rouge
int colorArray[MAXARRAY]; // contient la suite de chiffres pour les couleurs a afficher

void setup() {
  for(int i = 0; i < 4; i++)
  	pinMode(ledPin[i],OUTPUT); //programmation des broche de led comme sortie
	//INPUT
  pinMode(buttonPinRed,INPUT);digitalWrite(buttonPinRed,HIGH);
  pinMode(buttonPinGreen,INPUT);digitalWrite(buttonPinGreen,HIGH);
  pinMode(buttonPinYellow,INPUT);digitalWrite(buttonPinYellow,HIGH);
  pinMode(buttonPinBlue,INPUT);digitalWrite(buttonPinBlue,HIGH);
	pinMode(buttonPinMenu, INPUT);digitalWrite(buttonPinMenu, HIGH);
	//OUTPUT
  pinMode(ledStatePinGreen,OUTPUT);
  pinMode(ledStatePinYellow,OUTPUT);
  pinMode(ledStatePinRed,OUTPUT);
}


