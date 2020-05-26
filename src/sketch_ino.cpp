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

void Board::generate_sequence(){
  for(int i = 0; i < MAX_LEVEL; i++)
    sequence[i] = rand()%(4); //génére des chiffres aleatoire de 0 a 3
                               // 0 = vert, 1 = jaune, 2 = rouge, 3 = blue
}

void Board::numberPlayers(){
	unsigned int i=0;
	vector<Player *> v1;
	for(i=0; i<NUMBER_PLAYER; i++){
		v1.push_back(new Player(i,0));
	}

	for(i=0; i<4; i++)
		cout << v1[i]->getScore() << " ";
	cout<<endl;

	sleep(DELAY);
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
					cout << your_sequence[i] <<endl;
					cout << sequence[i] <<endl;
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
					cout << your_sequence[i] <<endl;
					cout << sequence[i] <<endl;
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
					cout << your_sequence[i] <<endl;
					cout << sequence[i] <<endl;
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
					cout << your_sequence[i] <<endl;
					cout << sequence[i] <<endl;
					sprintf(buf,"!!!!!!!!!!!!!!!Mauvaise séquence!!!!!!!!!!!!");
   				Serial.println(buf);
					wrong_sequence();
					return;
				}	
				digitalWrite(ledPinBlue, LOW);
			}
		}
	}
	sprintf(buf,"Bonne séquence");
	Serial.println(buf);
	right_sequence();
}

void Board::wrong_sequence(){
	for (int i = 0; i < 3; i++){
		digitalWrite(ledPinGreen, HIGH);
		digitalWrite(ledPinYellow, HIGH);
		digitalWrite(ledPinRed, HIGH);
		digitalWrite(ledPinBlue, HIGH);
		sleep(DELAY);
		digitalWrite(ledPinGreen, LOW);
		digitalWrite(ledPinYellow, LOW);
		digitalWrite(ledPinRed, LOW);
		digitalWrite(ledPinBlue, LOW);
		sleep(DELAY);;
	}
	level = 1;
}

void Board::right_sequence(){
	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinYellow, LOW);
	digitalWrite(ledPinRed, LOW);
	digitalWrite(ledPinBlue, LOW);
	sleep(DELAY);

	digitalWrite(ledPinGreen, HIGH);
	digitalWrite(ledPinYellow, HIGH);
	digitalWrite(ledPinRed, HIGH);
	digitalWrite(ledPinBlue, HIGH);
	sleep(DELAY);

	digitalWrite(ledPinGreen, LOW);
	digitalWrite(ledPinYellow, LOW);
	digitalWrite(ledPinRed, LOW);
	digitalWrite(ledPinBlue, LOW);
	sleep(DELAY);

	if (level < MAX_LEVEL)
		level++;
}

void Board::loop(){
	if (level == 1)
		generate_sequence();//generate a sequence;
		numberPlayers(); //determine le nombre de joueur 
	if (digitalRead(buttonPinMenu) == HIGH || level != 1){ //If start button is pressed or you're winning
		cout <<"level :" <<level<<endl;
		show_sequence();    //show the sequence
		sleep(2*DELAY); //enlever le fichier on5.txt qui représente le bouton Menu
		get_sequence();     //wait for your sequence
	}
}




