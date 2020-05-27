#include <iostream>
#include <list>
#include "joueur.h"
using namespace std;

Player::Player(){
		id = 0;
		score = 0;
}

Player::Player(int id1, int score1){
		id = id1;
		score = score1;
}

Player::~Player(){}

int Player::getID(){
	return id;
}

int Player::getScore(){
	return score;
}

void Player::Score(){
	score++;
}
