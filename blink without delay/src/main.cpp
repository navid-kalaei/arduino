/**********************************************************************
 * Blink Without Delay                                                *
 *                                                                    *
 * delay function make board pause entire processes                   *
 * this is a sample to how to make delay without using delay function *
 *                                                                    *
 * @author: Navid Kalaei <navidkalaei@gmail.com>                      *
 * @github: @navid-kalaei                                             *
 * @license: MIT                                                      *
 **********************************************************************/


#include "Arduino.h"

#ifndef LED_BUILTIN
#define  LED_BUILTIN 13
#endif

///////////////////////////
// time to wait in milis //
///////////////////////////

#define DELAY_TIME 1000

////////////
// uptime //
////////////

unsigned long int curTime = 0;

///////////////////////////////////
// last time LED_BUILTIN toggled //
///////////////////////////////////

unsigned long int prevTime = 0;

///////////////////////
//LED_BUILTIN status //
///////////////////////

bool ledStatus = false;

void setup() {
  // assign pin mode
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  curTime = millis();
  if(curTime-prevTime >= DELAY_TIME){
    //////////////////////////////////
    // update last time led toggled //
    //////////////////////////////////

    prevTime = curTime;

    ///////////////////////
    // toggle led status //
    ///////////////////////

    ledStatus = !ledStatus;

    //////////////////////////////////
    // assign led status to led pin //
    //////////////////////////////////

    digitalWrite(LED_BUILTIN, ledStatus);
  }
}
