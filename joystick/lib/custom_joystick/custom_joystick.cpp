/*******************************************************************
 * Custom joystick class for to work with joystick                 *
 *                                                                 *
 * Note: YOU MUST ALWAYS COLIBRATE BEFORE FIRST USAGE              *
 *            AND THRESHOLD IS NORMALIZED                                            *
 * @author: Navid Kalaei <navidkalaei@gmail.com>                   *
 * @license: MIT                                                   *
*******************************************************************/

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
  pinMode(pin, INPUT);
  this->pinX = pin;
}

void custom_joystick::attach_pin_y(short pin)
{
  pinMode(pin, INPUT);
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

void custom_joystick::calibrate()
{
  this->originX = analogRead(this->pinX);
  this->originY = analogRead(this->pinY);
  this->normalizedOriginX = this->normalize(this->originX);
  this->normalizedOriginY = this->normalize(this->originY);
}

void custom_joystick::set_threshold(int value)
{
    this->threshold = value;
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

int custom_joystick::get_origin_y()
{
  return this->originY;
}

int custom_joystick::get_normalized_origin_x()
{
  return this->normalize(this->originX);
}

int custom_joystick::get_normalized_origin_y()
{
  return this->normalize(this->originY);
}

int custom_joystick::get_x()
{
  return analogRead(this->pinX);
}

int custom_joystick::get_y()
{
  return analogRead(this->pinY);
}

int custom_joystick::get_normalized_x()
{
  int normalizedX = this->normalize(this->get_x());
  this->checkBoundry(normalizedX);
  return normalizedX;
}

int custom_joystick::get_normalized_y()
{
  int normalizedY = this->normalize(this->get_y());
  this->checkBoundry(normalizedY);
  return normalizedY;
}

short int custom_joystick::cmp(int value1, int value2)
{
  if(value1 > value2){
    return 1;
  }
  else if(value1 < -value2){
    return -1;
  }
  else{
    return 0;
  }
}

short int custom_joystick::get_direction_x()
{
  return this->cmp(this->get_normalized_x(), this->threshold);
}

short int custom_joystick::get_direction_y()
{
  return this->cmp(this->get_normalized_y(), this->threshold);
}
