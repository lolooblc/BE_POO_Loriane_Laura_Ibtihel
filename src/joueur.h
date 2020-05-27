#include <iostream>
using namespace std;


class Player {
private :
	int score;
	int id;

public :
	Player(){
		id = 0;
		score = 0;
	};
	Player(int id1, int score1){
		id = id1;
		score = score1;
	};
	int getID(){
		return id;
	};
	int getScore(){
		return score;
	};
	
	void Score(){
		cout<<"je suisla"<<endl;
		score++;
	};
};
