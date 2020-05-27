#include <iostream>
using namespace std;


class Player {
private :
	int score; //score du joueur
	int id; //id du joueur 

public :
	Player(); //constructeur

	virtual ~Player(); //destructeur

	Player(int id1, int score1);//constructeur

	int getID(); //Obtenir l'ID

	int getScore(); //Obtenir le score
	
	void Score(); //augmenter le score
};
