/*
 * Servo
 * read data from joystick, normalize, and write to servo
 *
 * @author: Navid Kalaei
 * @github: @navid-kalaei
 * @license: MIT
 */


#include "Arduino.h"

// time to wait in millis
#define DELAY_TIME 500

#define SERIAL_RATE 9600
#define JOY_PIN_X 0
#define JOY_PIN_Y 1

// boundries of analogRead()
#define ANALOG_READ_LOW 0
#define ANALOG_READ_HIGH 1023

// boundries for normalizing analogRead() from -90 to +90
#define NORMALIZE_BOUND_LOW -90
#define NORMALIZE_BOUND_HIGH 90

// the value that joystick has at first
// they're usefull in normalizing
short int joyXOrigin = 0;
short int joyYOrigin = 0;

short int joyXOriginNormalized = 0;
short int joyYOriginNormalized = 0;

short int joyValueX = 0;
short int joyValueY = 0;

short int joyValueXNormalized = 0;
short int joyValueYNormalized = 0;

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

void setup() {
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

void  loop() {
  joyValueX = analogRead(JOY_PIN_X);
  joyValueXNormalized = normalize(joyValueX) - joyXOriginNormalized;
  checkBoundries(joyValueXNormalized);

  joyValueY =  analogRead(JOY_PIN_Y);
  joyValueYNormalized = normalize(joyValueY) - joyYOriginNormalized;
  checkBoundries(joyValueYNormalized);

  delay(DELAY_TIME);
}
