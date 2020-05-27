#ifndef GAME_H_
#define GAME_H_

#include "MySensors.h"
#include "MyActuators.h"
#include "LCDscreen.h"

#define pinBR A0
#define pinBB A1
#define pinBG A2
#define pinBY A3
#define pinBMENU A4
#define pinLR 6
#define pinLB 7
#define pinLG 8
#define pinLY 9
#define pinBuzzer 10

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

class Game {
  protected:
    int velocity;
    int error_spot;//store the pin of the wrong LED, used only for tests
    static const int MAX_LEVEL;
    static int level;
  public:
    Game();  
    //generate a random sequence of number of pins (among the LED pins)
    int * generate_sequence();
    //make the 4 LED flash 3 times, emet a noise and display "GAME OVER"
    void wrong_sequence();
    //make the 4 LED flash once, emet a noise and display "WELL DONE!"
    void right_sequence();
    //light the LED in the sequence order, the lengh of the shown sequence correspond to the current level
    void show_sequence(int *sequence);
    //Compare which sequence the user is making
    void get_sequence(int *sequence);
    int choose_nb_of_players();
    //For tests---------------
    //return the current level
    int GetLevel();
    //light the LED when the button is pressed
    void test_boutons();
};





#endif
