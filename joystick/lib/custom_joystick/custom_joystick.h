/*******************************************************************
 * Custom joystick class for to work with joystick                 *
 *                                                                 *
 * Note: YOU MUST ALWAYS COLIBRATE BEFORE FIRST USAGE              *
 *          AND THERESHOLD IS NORMALIZED                                                       *
 * @author: Navid Kalaei <navidkalaei@gmail.com>                   *
 * @license: MIT                                                   *
*******************************************************************/

#ifndef ANALOG_READ_LOW
#define ANALOG_READ_LOW 0
#endif

#ifndef ANALOG_READ_HIGH
#define ANALOG_READ_HIGH 1023
#endif

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

  ///////////////////////////////////
  // threshold to detect direction //
  ///////////////////////////////////

  int threshold = 30;

  //////////////////////////////////////////////////////////////////////////////
  // get value and map it from analog boundries(0-1023) to joystick boundries //
  //////////////////////////////////////////////////////////////////////////////

  int normalize(int value);

  bool checkBoundry(int &value);
public:
  short int cmp(int value1, int value2);

  void attach_pin_x(short int pin);
  void attach_pin_y(short int pin);

  void set_lower_bound(int value);
  void set_higher_bound(int value);

  //////////////////////////////
  // init normalized origins. //
  //////////////////////////////

  void calibrate();

  void set_threshold(int value);

  //////////////////////////////////
  // return raw values of origins //
  //////////////////////////////////

  int get_origin_x();
  int get_origin_y();

  /////////////////////////////////////////
  // return normalized values of origins //
  /////////////////////////////////////////

  int get_normalized_origin_x();
  int get_normalized_origin_y();

  /////////////////////////////////////////////
  // return raw values read from analog pins //
  /////////////////////////////////////////////

  int get_x();
  int get_y();

  ////////////////////////////////////////////////////
  // return normalized values read from analog pins //
  ////////////////////////////////////////////////////

  int get_normalized_x();
  int get_normalized_y();

  ///////////////////////////////////////////////////////////
  // according to threshold return if direction the joy is //
  ///////////////////////////////////////////////////////////

  short int get_direction_x();
  short int get_direction_y();
};
