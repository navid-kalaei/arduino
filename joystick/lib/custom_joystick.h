/*******************************************************************
 * Custom joystick class for to work with joystick                 *
 *                                                                 *
 * Note: YOU MUST ALWAYS COLIBRATE BEFORE FIRST USAGE              *
 *                                                                 *
 * @author: Navid Kalaei <navidkalaei@gmail.com>                   *
 * @license: MIT                                                   *
*******************************************************************/

#define ANALOG_READ_LOW 0
#define ANALOG_READ_HIGH 1023

class custom_joystick {
private:
  short int pinX;
  short int pinY;

  //////////////////////////////////
  // joy pin values in its origin //
  //////////////////////////////////

  int originX = 0;
  int originY = 0;

  /////////////////////////////////
  // boundries for normalization //
  /////////////////////////////////

  int lowerBound = -90;
  int higherBound = 90;

  int normalizedOriginX;
  int normalizedOriginY;

  //////////////////////////////////////////////////////////////////////////////
  // get value and map it from analog boundries(0-1023) to joystick boundries //
  //////////////////////////////////////////////////////////////////////////////

  int normalize(int value);

  bool checkBoundry(int &value);
public:
  custom_joystick ();

  void attach_pin_x(short int pin);
  void attach_pin_y(short int pin);

  void set_lower_bound(int value);
  void set_higher_bound(int value);
  // init normalized origins.
  void colibrate();

  //////////////////////////////////
  // return raw values of origins //
  //////////////////////////////////

  short int get_origin_x();
  short int get_origin_y();

  /////////////////////////////////////////
  // return normalized values of origins //
  /////////////////////////////////////////

  int get_normalized_origin_x();
  int get_normalized_origin_y();

  ////////////////////////////////////////////////////
  // return normalized values read from analog pins //
  ////////////////////////////////////////////////////

  int get_normalized_x();
  int get_normalized_y();

  /////////////////////////////////////////////
  // return raw values read from analog pins //
  /////////////////////////////////////////////

  short int get_value_x();
  short int get_value_y();

  short int get_direction_x();
  short int get_direction_y();
};
