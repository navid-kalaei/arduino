/*******************************************************************
 * Custom joystick class for to work with joystick                 *
 *                                                                 *
 * Note: YOU MUST ALWAYS COLIBRATE BEFORE FIRST USAGE              *
 *                                                                 *
 * @author: Navid Kalaei <navidkalaei@gmail.com>                   *
 * @license: MIT                                                   *
*******************************************************************/


class custom_jostick {
private:
  short int pinX;
  short int pinY;

  //////////////////////////////////
  // joy pin values in its origin //
  //////////////////////////////////

  int originX;
  int originY;

  /////////////////////////////////
  // boundries for normalization //
  /////////////////////////////////

  int lowerBound;
  int higherBound;

  int normalizedOriginX;
  int normalizedOriginY;

  int normalizedX;
  int normalizedY;

  //////////////////////////////////////////////////////////////////////////////
  // get value and map it from analog boundries(0-1023) to joystick boundries //
  //////////////////////////////////////////////////////////////////////////////

  int normalize(int value);

public:
  custom_jostick ();
  virtual ~custom_jostick ();

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
