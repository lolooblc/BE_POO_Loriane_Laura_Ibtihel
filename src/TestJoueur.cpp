#include <iostream>
#include <vector>
#include "joueur.cpp"
using namespace std;



int main(int argc, char **argv) {
	unsigned int i=0;
	vector<Player *> v1;	
	for(i=0; i<4; i++){
		v1.push_back(new Player(i,0));
	}

	for(i=0; i<4; i++)
		cout << v1[i]->getScore() << " ";
	cout<<endl;

	for(i=0; i<4; i++)
		v1[i]->Score();	

	for(i=0; i<4; i++)
		cout << v1[i]->getScore() << " ";
	cout<<endl;


}
