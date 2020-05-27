#include <iostream>
#include <list>
#include "joueur.h"
using namespace std;

//constructeur
Player::Player(){
		id = 0;
		score = 0;
}

//constructeur
Player::Player(int id1, int score1){
		id = id1;
		score = score1;
}

//destructeur
Player::~Player(){}

//Obtenir l'ID
int Player::getID(){
	return id;
}

//Obtenir le score
int Player::getScore(){
	return score;
}

//augmenter le score
void Player::Score(){
	score++;
}
