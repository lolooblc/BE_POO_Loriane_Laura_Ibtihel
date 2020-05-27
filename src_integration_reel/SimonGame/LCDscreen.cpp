#include <Arduino.h> 
#include <LiquidCrystal.h>
#include "LCDscreen.h"


//constructor
LCDscreen::LCDscreen(const int mypin_rs, const int mypin_en, const int mypin_d4, const int mypin_d5, const int mypin_d6, const int mypin_d7):LiquidCrystal (mypin_rs, mypin_en, mypin_d4, mypin_d5, mypin_d6, mypin_d7){
    begin(16, 2);
}

//print the nature of the device
void LCDscreen::WhoAmI(){
  Serial.print("Je suis un ecran LCD");
}

//Display a text
void LCDscreen::Display(char text[]){
  print(text);
}

//clean the screen
void LCDscreen::CleanScreen(){
  clear();
}
