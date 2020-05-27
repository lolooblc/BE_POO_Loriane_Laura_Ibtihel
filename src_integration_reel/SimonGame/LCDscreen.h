#ifndef LCDSCREEN_H_
#define LCDSCREEN_H_

#include "Devices.h"
#include <LiquidCrystal.h>

class LCDscreen : public Devices, public LiquidCrystal {
  public:
  LCDscreen(const int mypin_rs, const int mypin_en, const int mypin_d4, const int mypin_d5, const int mypin_d6, const int mypin_d7);
  virtual void WhoAmI();
  //Display a text
  void Display(char text[]); 
  //clean the screen
  void CleanScreen(); 
};


#endif
