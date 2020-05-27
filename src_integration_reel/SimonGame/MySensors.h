#ifndef MYSENSORS_H_
#define MYSENSORS_H_

#include "Devices.h"

class Sensors : public Devices {
  protected:
    int pin;
    static int nbSensors;
  public:
    Sensors(int pin);
    virtual void WhoAmI();
    //read the sensor's state
    virtual int GetState(); 
};


//----------class for pushbutton------------------
class ExternalDigitalSensorButton : public Sensors {
  int pin;
  public:
    ExternalDigitalSensorButton(int mypin);
    void WhoAmI();
    int GetState();
};





#endif /*MYSENSORS_H_*/
