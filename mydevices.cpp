
#include "mydevices.h"

using namespace std;

//variable globale luminosite environnement
//static volatile int lumiosite_environnement = 200;

/*
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

*/

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

AnalogActuatorBuzzer::AnalogActuatorBuzzer(double f, int t):Device(),frequency(f),temps(t){
}

void AnalogActuatorBuzzer::run(){
    while(1){
    sleep(3);
    cout<<"pin pin"<<endl;
    }
}

/*
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
*/
