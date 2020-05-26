#ifndef MYDEVICES_H
#define MYDEVICES_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"



//classe sensor 
class Actuator : public Device {
protected : 
  // temps entre 2 affichage de l etat de la led
  int temps;
public :
	Actuator();
	virtual void run();
}; 

// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class DigitalActuatorLED: public Actuator {
protected:
  // etat de la LED
  int state;
	// nom de la LED
	string nomLeds;
  
public:
    // initialisation du temps de rafraichissement
  DigitalActuatorLED(int t, string nomLed);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};






// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Actuator{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];

  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};



//classe sensor 
class Sensor : public Device {
protected : 
  // temps entre 2 affichage de l'etat du boutton
	int temps;
public :
	//constructeur
	Sensor();
	virtual void run();
}; 

class ExternalDigitalSensorButton : public Sensor {
 protected :
  //etat du bouton
  int button_state;
	// nom du fichier correspondant au boutton
	string textes;
 public :
  ExternalDigitalSensorButton(int t, string texte);
  int updateState();
  virtual void run();
};


#endif
