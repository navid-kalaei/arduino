/******************************************************
 * Read rate from joystick and set to led to blink    *
 * Notice: Only X direction is available for joystick *
 *                                                    *
 * @author: Navid Kalaei <navidkalaei@gmial.com>      *
 ******************************************************/


#include "Arduino.h"

// serial rate
#define SERIAL_RATE 9600
// joystick pin x on analog in
#define JOY_PIN_X 0
// define LED built in pin number
#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

// analogRead upper bound
#define ANALOG_UPPER_BOUND 1023
// analogRead lower bound
#define ANALOG_LOWER_BOUND 0

// thereshold to check if satisfied stable led status to on or off
// according to boundries
#define ANALOG_THERESHOLD 10

// the most time to wait in milliseconds
#define TIME_UPPER_BOUND 1500
// the least time to wait in milliseconds
#define TIME_LOWER_BOUND 250
// time interval
#define TIME_INTERVAL 250

#define ANALOG_ORIGIN 512

// the range of analogRead is 0 to 1023 and joystick pin x is an analog one
unsigned short joy_x = 0;
// calibrated joy x
unsigned short colibrated_joy_x = 0;
// mapped joy x data to time boundries (TIME_LOWER_BOUND, TIME_UPPER_BOUND)
unsigned short mapped_time = 0;

// difference between joy and it's origin (512) to calibrate
short int fault = 0;

void print_value_msg(int value){
    Serial.print("Wainting for: ");
    Serial.print(value);
    Serial.println(" milliseconds");
}

void blink(int delay_time){
  /*
   * get time to delay in millis and blink with that delay time
   *
   * @param delay_time: is time to delay
   * @return: void
   */

  //turn led builtin on
  digitalWrite(LED_BUILTIN, HIGH);
  //wait
  delay(delay_time);
  //turn led builtin off
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_time);
}

short int colibrate_analog(short int value, short int fault){
  /*
   * get a value between analog range [0, 1023] and correct the fault
   *
   * @param value
   */

  return value + fault;
}

int analog_to_time(int analog_value){
  /*
   * gets a value in analog read range [0, 1023] and map to time boundries
   *
   * @param analog_value: value in anlaog range [0, 1023]
   * @return: the value mapped to time boundries
   */

  // set default value to maximum delay time
  int mapped_time = TIME_UPPER_BOUND;
   mapped_time = map(analog_value,
    ANALOG_LOWER_BOUND, ANALOG_UPPER_BOUND,
    TIME_LOWER_BOUND, TIME_UPPER_BOUND);

  return mapped_time;
}

void setup(){
  // attach pin mode of joystick pin x
  pinMode(JOY_PIN_X, INPUT);
  // set LED biultin output
  pinMode(LED_BUILTIN, OUTPUT);

  // joy stick fault to use for collibration
  fault = ANALOG_ORIGIN - analogRead(JOY_PIN_X);

  // wait until serial port is not available
  while(!Serial);
  Serial.println("Move joystick to change rate of blinking.");
  Serial.println("Notice only X direction is available.");
  Serial.println();
}

void loop(){
  //read data from joystic pin x
  joy_x = analogRead(JOY_PIN_X);
  // colibrate joy value x
  colibrated_joy_x = colibrate_analog(joy_x, fault);
  //from digital read to time boundries
  if(ANALOG_UPPER_BOUND - colibrated_joy_x < ANALOG_THERESHOLD){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(colibrated_joy_x - ANALOG_LOWER_BOUND < ANALOG_THERESHOLD){
    digitalWrite(LED_BUILTIN, LOW);
  }
  else{
    mapped_time = analog_to_time(colibrated_joy_x);
    print_value_msg(mapped_time);
    blink(mapped_time);
  }
}
