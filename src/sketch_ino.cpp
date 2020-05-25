#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
	// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
	

	//INPUT button
	pinMode(PIN_GREEN_BUTTON,INPUT);//bouton poussoir LED verte
	pinMode(PIN_YELLOW_BUTTON,INPUT);//bouton poussoir LED jaune
	pinMode(PIN_RED_BUTTON,INPUT);//bouton poussoir LED rouge
	pinMode(PIN_BLUE_BUTTON,INPUT);//bouton poussoir LED bleue


	//OUTPUT LED
  pinMode(ledPinGreen,OUTPUT);
  pinMode(ledPinYellow,OUTPUT);
  pinMode(ledPinRed,OUTPUT);
	pinMode(ledPinBlue, OUTPUT);
}

// Message de démarrage
void Board::beginMessage(){
  char buf[100];
  sprintf(buf,"Départ du jeu ");
  Serial.println(buf);
  bus.write(1,buf,100);
	sleep(DELAY);
}



int sequence[MAX_LEVEL]; // contient la suite de chiffres pour les couleurs a afficher
//int your_sequence[MAX_LEVEL];

void Board::generate_sequence(){
  for(int i = 0; i < MAX_LEVEL; i++)
    sequence[i] = rand()%(4); //génére des chiffres aleatoire de 0 a 3
                               // 0 = vert, 1 = jaune, 2 = rouge, 3 = blue
}


void Board::randomSequenceDisplay(int value){
  //affichage LEDs
	char buf[100];
  for(int i = 0; i <= value; i++){
    digitalWrite(1 + sequence[i],HIGH);
		if (1 + sequence[i] == 1 ) {
			sprintf(buf,"La led verte s'allume ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 2) {
   		sprintf(buf,"La led jaune s'allume ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 3) {
    	sprintf(buf,"La led rouge s'allume ");
    	Serial.println(buf);
		}
		else {
   		sprintf(buf,"La led bleue s'allume ");
    	Serial.println(buf);
		}
    sleep(DELAY);

    digitalWrite(1 + sequence[i], LOW); 
		if (1 + sequence[i] == 1 ) {
			sprintf(buf,"La led verte s'éteind ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 2) {
   		sprintf(buf,"La led jaune s'éteind ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 3) {
    	sprintf(buf,"La led rouge s'éteind ");
    	Serial.println(buf);
		}
		else {
   		sprintf(buf,"La led bleue s'éteind ");
    	Serial.println(buf);
		}
		sleep(DELAY);
		break;
  }
}


void Board::answerLED(int value){
  // Affichage LED
  digitalWrite(1+value, HIGH);
	sleep(DELAY);
  digitalWrite(1+value, LOW);
}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
	int state_buttonGreen;
	int state_buttonYellow;
	int state_buttonRed;
	int state_buttonBlue;
	int buttonCode = 0;
  //int val;
  static int cpt=0;
  //static int bascule=0;
  //int i=0;

	generate_sequence();
	for(int i = 0; i <= cpt; i++){ //boucle extérieure
		randomSequenceDisplay(i);

		if(analogRead(PIN_GREEN_BUTTON)==1)
			buttonCode = 0;
		if(analogRead(PIN_YELLOW_BUTTON)==1)
			buttonCode = 1;
		if(analogRead(PIN_RED_BUTTON)==1)
			buttonCode = 2;
		if(analogRead(PIN_BLUE_BUTTON)==1)
			buttonCode = 3;
		answerLED(buttonCode);






	 // lecture sur la pin 5 :
   state_buttonGreen=analogRead(PIN_GREEN_BUTTON);
   sprintf(buf,"etat du bouton poussoir LED verte : %d",state_buttonGreen);
   Serial.println(buf);
	 // lecture sur la pin 6 :
   state_buttonYellow=analogRead(PIN_YELLOW_BUTTON);
   sprintf(buf,"etat du bouton poussoir LED jaune : %d",state_buttonYellow);
   Serial.println(buf);
		if(cpt%5==0){
      // tous les 5 fois on affiche sur l ecran le bouton
      sprintf(buf,"%d",state_buttonYellow);
      bus.write(1,buf,100);
		}

	 // lecture sur la pin 7 :
   state_buttonRed=analogRead(PIN_RED_BUTTON);
   sprintf(buf,"etat du bouton poussoir LED rouge : %d",state_buttonRed);
   Serial.println(buf);
		if(cpt%5==0){
      // tous les 5 fois on affiche sur l ecran le bouton
      sprintf(buf,"%d",state_buttonRed);
      bus.write(1,buf,100);
		}

	 // lecture sur la pin 8 :
   state_buttonBlue=analogRead(PIN_BLUE_BUTTON);
   sprintf(buf,"etat du bouton poussoir LED blue : %d",state_buttonBlue);
   Serial.println(buf);
		if(cpt%5==0){
      // tous les 5 fois on affiche sur l ecran le bouton
      sprintf(buf,"%d",state_buttonBlue);
      bus.write(1,buf,100);
		}
	}
	cpt++;
	sleep(DELAY);
	



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
		
/*

		// on eteint et on allume la LED
  	if(bascule) {
    	digitalWrite(ledPinGreen,HIGH);
    	sprintf(buf,"led verte allume");
    	Serial.println(buf);
    	digitalWrite(ledPinYellow,HIGH);
    	sprintf(buf,"led jaune allume");
    	Serial.println(buf);
   		digitalWrite(ledPinRed,HIGH);
    	sprintf(buf,"led rouge allume");
    	Serial.println(buf);
   	 	digitalWrite(ledPinBlue,HIGH);
    	sprintf(buf,"led bleue allume");
    	Serial.println(buf);
			sleep(DELAY);
		}
  	else {
  		digitalWrite(ledPinGreen,LOW);
   		sprintf(buf,"led verte eteinte");
    	Serial.println(buf);
   		digitalWrite(ledPinYellow,LOW);
   		sprintf(buf,"led jaune eteinte");
    	Serial.println(buf);
   		digitalWrite(ledPinRed,LOW);
   		sprintf(buf,"led rouge eteinte");
    	Serial.println(buf);
   		digitalWrite(ledPinBlue,LOW);
   		sprintf(buf,"led blue eteinte");
    	Serial.println(buf);
			sleep(DELAY);
		}
 	 	bascule=1-bascule;
*/


}



