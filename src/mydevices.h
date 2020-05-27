#ifndef MYDEVICES_H
#define MYDEVICES_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"



//classe Actuator 
class Actuator : public Device {
protected : 
  // temps entre 2 affichage de l etat de la led
  int temps;
public :
	Actuator();
	virtual void run();
}; 



// Actionneur digital LED
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






// Actionneur sur le bus I2C
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


// Actionneur analogue un buzzeur
class AnalogActuatorBuzzer: public Actuator {
protected:
  // fréquence du buzzeur
  double delay_value;
  // temps du klaxonnage
  int beeplong;
  // erreur ou pas
  //int state;

public:
    // initialisation du temps de rafraichissement et de la fréquence
  AnalogActuatorBuzzer(double delay_value,int beeplong);
   int writeError();
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
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

// Actionneur button
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
