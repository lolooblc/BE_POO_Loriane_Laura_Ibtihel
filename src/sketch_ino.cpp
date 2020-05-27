#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "core_simulation.h"
#include "joueur.cpp"

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
  sprintf(buf,"Simon Game ");
  Serial.println(buf);
  bus.write(1,buf,100);
	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinYellow, LOW);
	digitalWrite(ledPinRed, LOW);
	digitalWrite(ledPinBlue, LOW);
	cout << "Nombre devices branchés: ";
	cout <<Device::devicesNumber()<<endl;

	sleep(DELAY);
}



int sequence[MAX_LEVEL]; // contient la suite de chiffres pour les couleurs a afficher
int your_sequence[MAX_LEVEL];
int level = 1;
int stop = 1;
int id = 0;

vector<Player *> v1;


void Board::setUpListe(){
		unsigned int i=0;
		for(i=0; i<(NUMBER_PLAYER+1); i++){
			v1.push_back(new Player(i,0));
		}
}


void Board::generate_sequence(){
  for(int i = 0; i < MAX_LEVEL; i++)
    sequence[i] = rand()%(4); //génére des chiffres aleatoire de 0 a 3
                               // 0 = vert, 1 = jaune, 2 = rouge, 3 = blue
}

void Board::show_sequence(){
	char buf[100];
	for (int i = 0; i < level; i++){

    digitalWrite(1 + sequence[i],HIGH); //Allume LED

		if (1 + sequence[i] == 1 ) {
			sprintf(buf,"///////// La led verte s'allume ///////// ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 2) {
   		sprintf(buf,"////////// La led jaune s'allume ///////// ");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 3) {
    	sprintf(buf,"///////// La led rouge s'allume /////////");
    	Serial.println(buf);
		}
		else {
   		sprintf(buf,"///////// La led bleue s'allume /////////");
    	Serial.println(buf);
		}
		sleep(DELAY/2);

    digitalWrite(1 + sequence[i], LOW); //Eteint LED

		if (1 + sequence[i] == 1 ) {
			sprintf(buf,"///////// La led verte s'éteind /////////");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 2) {
   		sprintf(buf,"///////// La led jaune s'éteind /////////");
    	Serial.println(buf);
		}
		else if (1 + sequence[i] == 3) {
    	sprintf(buf,"///////// La led rouge s'éteind /////////");
    	Serial.println(buf);
		}
		else {
   		sprintf(buf,"///////// La led bleue s'éteind /////////");
    	Serial.println(buf);
		}
		sleep(DELAY/2);
	}
}

void Board::get_sequence() {
	char buf[100];
	int flag = 0; //this flag indicates if the sequence is correct
	for (int i = 0; i < level; i++){
		sleep(DELAY);
		sprintf(buf,"*************Saississez ***************");
    Serial.println(buf);
		flag = 0;
		while(flag == 0){
			if (digitalRead(PIN_GREEN_BUTTON) == HIGH){
				digitalWrite(ledPinGreen, HIGH);
				your_sequence[i] = ledPinGreen;
				flag = 1;
				sleep(DELAY);
				if (your_sequence[i] != (1+sequence[i])){
					sprintf(buf,"!!!!!!!!!!!!!!!!!Mauvaise séquence!!!!!!!!!!!!");
   				Serial.println(buf);
					wrong_sequence();
					return;
				}
				digitalWrite(ledPinGreen, LOW);
			}

			if (digitalRead(PIN_YELLOW_BUTTON) == HIGH){
				digitalWrite(ledPinYellow, HIGH);
				your_sequence[i] = ledPinYellow;
				flag = 1;
				sleep(DELAY);
				if (your_sequence[i] != (1+sequence[i])){
					sprintf(buf,"!!!!!!!!!!!!!!Mauvaise séquence!!!!!!!!!!!");
   				Serial.println(buf);
					wrong_sequence();
					return;
				}
				digitalWrite(ledPinYellow, LOW);
			}

			if (digitalRead(PIN_RED_BUTTON) == HIGH){
				digitalWrite(ledPinRed, HIGH);
				your_sequence[i] = ledPinRed;
				flag = 1;
				sleep(DELAY);
				if (your_sequence[i] != (1+sequence[i])){
					sprintf(buf,"!!!!!!!!!!!!Mauvaise séquence!!!!!!!!!!!!!!!!");
   				Serial.println(buf);
					wrong_sequence();
					return;
				}
				digitalWrite(ledPinRed, LOW);
			}

			if (digitalRead(PIN_BLUE_BUTTON) == HIGH){
				digitalWrite(ledPinBlue, HIGH);
				your_sequence[i] = ledPinBlue;
				flag = 1;
				sleep(DELAY);
				if (your_sequence[i] != (1+sequence[i])){
					sprintf(buf,"!!!!!!!!!!!!!!!Mauvaise séquence!!!!!!!!!!!!");
   				Serial.println(buf);
					wrong_sequence();
					return;
				}	
				digitalWrite(ledPinBlue, LOW);
			}
		}
	}
	sprintf(buf,"!!!!!!!!!!!! Bonne séquence !!!!!!!!!!!!!!!!!!!");
	Serial.println(buf);
	right_sequence();
}

void Board::wrong_sequence(){
	for (int i = 0; i < 3; i++){
		digitalWrite(ledPinGreen, HIGH);
		digitalWrite(ledPinYellow, HIGH);
		digitalWrite(ledPinRed, HIGH);
		digitalWrite(ledPinBlue, HIGH);
		sleep(DELAY/2);
		digitalWrite(ledPinGreen, LOW);
		digitalWrite(ledPinYellow, LOW);
		digitalWrite(ledPinRed, LOW);
		digitalWrite(ledPinBlue, LOW);
		sleep(DELAY/2);;
	}
	level = 1;
	stop = 1;
	cout <<"Pour passer au prochain joueur appuyer sur menu"<<endl;
	
}

void Board::right_sequence(){
	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinYellow, LOW);
	digitalWrite(ledPinRed, LOW);
	digitalWrite(ledPinBlue, LOW);
	sleep(DELAY/2);

	digitalWrite(ledPinGreen, HIGH);
	digitalWrite(ledPinYellow, HIGH);
	digitalWrite(ledPinRed, HIGH);
	digitalWrite(ledPinBlue, HIGH);
	sleep(DELAY/2);

	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinYellow, LOW);
	digitalWrite(ledPinRed, LOW);
	digitalWrite(ledPinBlue, LOW);
	sleep(DELAY/2);

	if (level < MAX_LEVEL)
		level++;
}



void Board::loop(){
	if (level == 1){
		generate_sequence();//génère la sequence;
	}
	if (stop == 1){
			id ++;
			stop = 0;
	}
	if (digitalRead(buttonPinMenu) == HIGH || level != 1){ //Si le bouton menu est appuyé ou si le joueur a gagné
		cout << "C'est au tour du joueur :" <<v1[id]->getID() << endl; //affiche le tour du joueur
		show_sequence();    //Montre la séquence
		sleep(DELAY); //enlever le bouton Menu
		get_sequence();     //attend que le joueur saissise sa séquence 
		v1[id]->Score();	//incrémente le score
		cout<<endl;
		cout << "Ton score est de : " << v1[id]->getScore() << endl; //affiche le score du joueur 
	}
}




