#ifndef MYACTUATORS_H_
#define MYACTUATORS_H_

#include "Devices.h"

class Actuators : public Devices {
  protected:
    int pin;
    static int nbActuators;
  public:
    Actuators(int pin);
    virtual void WhoAmI();
    //Write high or low in the pin's actuator
    virtual void Write(int HoL); //in argument : HIGH or LOW, means 1 or 0
};


//----------class for LEDs------------------

class DigitalActuatorLED : public Actuators{
  public:
    DigitalActuatorLED(int pin);
    virtual void WhoAmI();
    virtual void Write(int HoL);
};

//----------class for buzzers------------------

class DigitalActuatorBuzzer : public Actuators{
  protected :
    double delay_value;
    //time of buzzer's vibration (in nb of iterations)
    int beeplong;
   public:
    DigitalActuatorBuzzer(int pin, double delay_value);
    virtual void WhoAmI();
    virtual void Write(int HoL); //useful only for tests
    void ring();
};



#endif
