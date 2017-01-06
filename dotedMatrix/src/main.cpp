#include "Arduino.h"
#include "LedControl.h"
#include <map>

// address of display
#define DISPLAY_ADDR 0

#define DELAY_TIEME 1000

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

void setup(){
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(DISPLAY_ADDR,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(DISPLAY_ADDR,8);
  /* and clear the display */
  lc.clearDisplay(DISPLAY_ADDR);
}

void loop(){

}
