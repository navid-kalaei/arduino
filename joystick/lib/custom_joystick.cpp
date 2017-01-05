#include "Arduino.h"
#include "custom_joystick.h"

int custom_joystick::normalize(int value)
{
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
    this->lowerBound, this->higherBound);
}

void custom_joystick::attach_pin_x(short pin)
{
  this->pinX = pin;
}

void custom_joystick::attach_pin_y(short pin)
{
  this->pinY = pin;
}
