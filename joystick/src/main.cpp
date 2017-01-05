/***********************************************************************
 * Joystick                                                            *
 * read joystick data, normalize from -90 to +90, write data to serial *
 *                                                                     *
 * @author: Navid Kalaei <navidkalaie@gmail.com>                       *
 * @github: @navid-kalaei                                              *
 * @license: MIT                                                       *
 ***********************************************************************/


#include "Arduino.h"
#include <custom_joystick.h>

// time to wait in millis
#define DELAY_TIME 250

#define SERIAL_RATE 9600
#define JOY_PIN_X 0
#define JOY_PIN_Y 1

custom_joystick joy;

void setup(){
  joy.attach_pin_x(JOY_PIN_X);
  joy.attach_pin_y(JOY_PIN_Y);

  joy.calibrate();

  // wait until Serail is not available
  while(!Serial);
  Serial.begin(SERIAL_RATE);
}

void loop(){
  Serial.print(joy.get_x());
  Serial.print(' ');
  Serial.print(joy.get_calibrated_x());
  Serial.print(" - ");
  Serial.print(joy.get_y());
  Serial.print(' ');
  Serial.println(joy.get_calibrated_y());

  delay(DELAY_TIME);
}
