#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
	// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
	
  /*
	//INPUT button
  pinMode(buttonPinRed,INPUT);digitalWrite(buttonPinRed,HIGH);
  pinMode(buttonPinGreen,INPUT);digitalWrite(buttonPinGreen,HIGH);
  pinMode(buttonPinYellow,INPUT);digitalWrite(buttonPinYellow,HIGH);
  pinMode(buttonPinBlue,INPUT);digitalWrite(buttonPinBlue,HIGH);

	pinMode(buttonPinMenu, INPUT);digitalWrite(buttonPinMenu, HIGH);
*/

	//OUTPUT LED
  pinMode(ledStatePinGreen,OUTPUT);
  pinMode(ledStatePinYellow,OUTPUT);
  pinMode(ledStatePinRed,OUTPUT);
	pinMode(ledStatePinBlue, OUTPUT);
}

// Message de démarrage
void Board::beginMessage(){
  char buf[100];
  sprintf(buf,"Bienvenue ");
  Serial.println(buf);
  bus.write(1,buf,100);
}

// la boucle de controle arduino
void Board::loop(){
  //char buf[100];
  //int val;
  //static int cpt=0;
  static int bascule=0;
  //int i=0;

/*
  for(i=0;i<10;i++){

    // lecture sur la pin 1 :
    val=analogRead(1);
    sprintf(buf,"led1 %d",val);
    Serial.println(buf);
    if(cpt%5==0){
      // tous les 5 fois on affiche sur l ecran la led1
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);
		}


		// lecture sur la pin 2 : capteur de luminosité
    val=analogRead(2);
    sprintf(buf,"luminosité %d",val);
    Serial.println(buf);

    if(cpt%5==0){
      // tous les 5 fois on affiche sur l ecran la luminosité
      sprintf(buf,"%d",val);
      bus.write(2,buf,100);
    }

    cpt++;
		sleep(1);

	}*/

		// on eteint et on allume la LED
  	if(bascule) {
    	digitalWrite(ledStatePinGreen,HIGH);
    	digitalWrite(ledStatePinYellow,HIGH);
   		digitalWrite(ledStatePinRed,HIGH);
   	 	digitalWrite(ledStatePinBlue,HIGH);
		}
  	else {
  		digitalWrite(ledStatePinGreen,LOW);
   		digitalWrite(ledStatePinYellow,LOW);
   		digitalWrite(ledStatePinRed,LOW);
   		digitalWrite(ledStatePinBlue,LOW);
		}
 	 	bascule=1-bascule;
}


