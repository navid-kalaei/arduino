/****************************************************************
 * Servo                                                        *
 * read joystick data, normalize, write to servo                *
 *                                                              *
 * known issues: if it won't work, open serial monitor then try *
 *                                                              *
 * @author: Navid Kalaei <navidkalaie@gmail.com>                *
 * @github: @navid-kalaei                                       *
 * @license: MIT                                                *
 ****************************************************************/




#include "Arduino.h"
#include "Servo.h"

// time to wait in millis
#define DELAY_TIME 200

#define SERIAL_RATE 9600
#define JOY_PIN_X 0
#define JOY_PIN_Y 1

#define SERVO_PIN 9

// boundries of analogRead()
#define ANALOG_READ_LOW 0
#define ANALOG_READ_HIGH 1023

// boundries for normalizing analogRead() from -90 to +90
#define NORMALIZE_BOUND_LOW -90
#define NORMALIZE_BOUND_HIGH 90
// use this number to shift normalize value be between 0 to 180
#define NORMALIZE_ORIGIN 90

// the value that joystick has at first
// they're usefull in normalizing
short int joyXOrigin = 0;

short int joyXOriginNormalized = 0;

short int joyValueX = 0;

short int joyValueXNormalized = 0;

Servo myServo;

int myServoPos = 0;

short int normalize(short int value){
  /*
   * a wrapper for map built-in function
   *
   * @param value: is within analogRead boundries
   * @return: normalize value within normalize boundries
   */

   // https://www.arduino.cc/en/Reference/Map
   // map(value, fromLow, fromHigh, toLow, toHigh)
   return map(value,
    ANALOG_READ_LOW, ANALOG_READ_HIGH,
    NORMALIZE_BOUND_LOW, NORMALIZE_BOUND_HIGH);
}

void checkBoundries(short int &value){
  /*
   * check if value is between normalized boudries or reset it to a boundry
   *
   * @param value: to check
   * @return: void
   */

   if(value > NORMALIZE_BOUND_HIGH){
     value = NORMALIZE_BOUND_HIGH;
   }
   else if(value < NORMALIZE_BOUND_LOW){
     value = NORMALIZE_BOUND_LOW;
   }
}

void setup(){
  myServo.attach(SERVO_PIN);

  // initialize joystick pins
  pinMode(JOY_PIN_X, INPUT);

  joyXOrigin = analogRead(JOY_PIN_X);

  joyXOriginNormalized = normalize(joyXOrigin);

  // wait until Serail is not available
  while(!Serial);
  Serial.begin(SERIAL_RATE);
}

void loop(){
  joyValueX = analogRead(JOY_PIN_X);
  joyValueXNormalized = normalize(joyValueX) - joyXOriginNormalized;
  checkBoundries(joyValueXNormalized);

  myServoPos = joyValueXNormalized + NORMALIZE_ORIGIN;
  myServo.write(myServoPos);
  //Serial.println(myServoPos);

  // delay(DELAY_TIME);
}
