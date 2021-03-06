/*************************************************
 * Blink                                         *
 * Turns on an LED on for one second,            *
 * then off for one second, repeatedly.          *
 *                                               *
 * @author: Navid Kalaei <navidkalaei@gmial.com> *
 * @github: @navid-kalaei                        *
 * @license: MIT                                 *
 *************************************************/

#include "Arduino.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

//////////////////
// time to wait //
//////////////////

#define DELAY_TIME 1000

void setup()
{
  //////////////////////////////////////////////
  // initialize LED digital pin as an output. //
  //////////////////////////////////////////////

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  /////////////////////////////////////////////////
  // turn the LED on (HIGH is the voltage level) //
  /////////////////////////////////////////////////

  digitalWrite(LED_BUILTIN, HIGH);

  ///////////////////////
  // wait for a second //
  ///////////////////////

  delay(DELAY_TIME);

  ////////////////////////////////////////////////
  // turn the LED off by making the voltage LOW //
  ////////////////////////////////////////////////

  digitalWrite(LED_BUILTIN, LOW);

  ///////////////////////
  // wait for a second //
  ///////////////////////

  delay(DELAY_TIME);
}
