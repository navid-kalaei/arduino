/***********************************************************************
 * Joystick                                                            *
 * read joystick data, normalize from -90 to +90, write data to serial *
 *                                                                     *
 * @author: Navid Kalaei <navidkalaie@gmail.com>                       *
 * @github: @navid-kalaei                                              *
 * @license: MIT                                                       *
 ***********************************************************************/


#include "Arduino.h"

// time to wait in millis
#define DELAY_TIME 1000

#define SERIAL_RATE 9600
#define JOY_PIN_X 0
#define JOY_PIN_Y 1


void setup(){
  // initialize joystick pins
  pinMode(JOY_PIN_X, INPUT);
  pinMode(JOY_PIN_Y, INPUT);

  joyXOrigin = analogRead(JOY_PIN_X);
  joyYOrigin = analogRead(JOY_PIN_Y);

  joyXOriginNormalized = normalize(joyXOrigin);

  joyYOriginNormalized = normalize(joyYOrigin);

  // wait until Serail is not available
  while(!Serial);
  Serial.begin(SERIAL_RATE);
}

void loop(){
  joyValueX = analogRead(JOY_PIN_X);
  joyValueXNormalized = normalize(joyValueX) - joyXOriginNormalized;
  checkBoundries(joyValueXNormalized);

  joyValueY =  analogRead(JOY_PIN_Y);
  joyValueYNormalized = normalize(joyValueY) - joyYOriginNormalized;
  checkBoundries(joyValueYNormalized);

  Serial.print(joyValueX);
  Serial.print(' ');
  Serial.print(joyValueXNormalized);
  Serial.print(" - ");
  Serial.print(joyValueY);
  Serial.print(' ');
  Serial.println(joyValueYNormalized);

  delay(DELAY_TIME);
}
