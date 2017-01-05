/*****************************************************************
 * Servo                                                         *
 * read joystick data, normalize, write to servo                 *
 *                                                               *
 * @author: Navid Kalaei <navidkalaie@gmail.com>                 *
 * @github: @navid-kalaei                                        *
 * @license: MIT                                                 *
*****************************************************************/


#include "Arduino.h"
#include "Servo.h"
#include "custom_joystick.h"

// time to wait in millis
#define DELAY_TIME 200

#define SERIAL_RATE 9600
#define JOY_PIN_X 0
#define JOY_PIN_Y 1

#define SERVO_PIN 9

// servo can turn from 0 to 180 so it's origin is 90
#define SERVO_ORIGIN 90

custom_joystick joy;

Servo myServo;

int myServoPos = 0;

void setup(){
  joy.attach_pin_x(JOY_PIN_X);
  joy.attach_pin_y(JOY_PIN_Y);
  joy.calibrate();

  myServo.attach(SERVO_PIN);

  // wait until Serail is not available
  // while(!Serial);
  // Serial.begin(SERIAL_RATE);
}

void loop(){
  myServoPos = joy.get_calibrated_x() + SERVO_ORIGIN;
  myServo.write(myServoPos);

  //Serial.println(myServoPos);
  //delay(DELAY_TIME);
}
