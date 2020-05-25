#ifndef MYDEVICES_H
#define MYDEVICES_H


#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"


// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class DigitalActuatorLED: public Device {
protected:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;

	string nomLeds;
  
public:
    // initialisation du temps de rafraichissement
  DigitalActuatorLED(int t, string nomLed);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};






// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];

  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};



class ExternalDigitalSensorButton : public Device {
 protected :
  //etat du bouton
  int button_state;
  // temps entre 2 affichage de l etat de la led
  int temps;
	// nom du fichier correspondant au boutton
	string textes;
 public :
  ExternalDigitalSensorButton(int t, string texte);
  int updateState();
  virtual void run();
};


#endif
