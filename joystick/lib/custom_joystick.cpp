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

void custom_joystick::set_lower_bound(int value)
{
  this->lowerBound = value;
}

void custom_joystick::set_higher_bound(int value)
{
  this->higherBound = value;
}

void custom_joystick::colibrate()
{
  this->originX = analogRead(this->pinX);
  this->originY = analogRead(this->pinY);
  this->normalizedOriginX = this->normalize(this->originX);
  this->normalizedOriginY = this->normalize(this->originY);
}

 bool custom_joystick::checkBoundry(int &value)
{
  /*
   * check if value is between normalized boudries or reset it to a boundry
   *
   * @param value: to check
   * @return: true if value is valid or false otherwise
   */

   if(value > this->higherBound){
     value = this->higherBound;
     return false;
   }
   else if(value < this->lowerBound){
     value = this->lowerBound;
     return false;
   }

   return true;
 }

int custom_joystick::get_origin_x()
{
  return this->originX;
}
