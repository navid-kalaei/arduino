#include "Arduino.h"
#include "LedControl.h"
#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

byte * char_to_byte_array(char c);
