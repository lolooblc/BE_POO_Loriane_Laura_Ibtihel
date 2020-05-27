#include "Game.h"

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  Game SimonGame;
  Serial.println(SimonGame.GetLevel());
   
  static int *sequence;
  sequence=SimonGame.generate_sequence(); //generate a sequence;

  //do nothing while the menu button isn't pressed
  while (digitalRead(pinBMENU) == LOW && SimonGame.GetLevel() == 1){
    
  }
  
  while (digitalRead(pinBMENU) == HIGH || SimonGame.GetLevel() != 1){ //If start button is pressed or you're winning//

    SimonGame.show_sequence(sequence);
    SimonGame.get_sequence(sequence);     //wait for the player's sequence    
  }
}
