#include <iostream>
using namespace std;


class Player {
private :
	int score;
	int id;

public :
	Player();

	Player(int id1, int score1);

	int getID();

	int getScore();
	
	void Score();
};
