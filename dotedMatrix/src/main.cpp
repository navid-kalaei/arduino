#include "Arduino.h"
#include "LedControl.h"
#include "CharToByteArray.h"

// address of display
#define DISPLAY_ADDR 0

#define DELAY_TIME 1000

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */

#define DIN 12
#define CS 11
#define CLK 10
#define NUMBER_OF_LED_MATRICES 1
#define SIZE_OF_LED_MATRIX 8
// brightness of led matrix (max value is 15)
#define LED_MATRIX_INENSITY 8
LedControl lc=LedControl(DIN, CS, CLK, NUMBER_OF_LED_MATRICES);

// mapped char to byte array from CharToByteArray::char_to_byte_array
byte * bytedChar;

void print_char(char c)
{
  bytedChar = char_to_byte_array(c);
  for (size_t i = 0; i < SIZE_OF_LED_MATRIX; i++) {
    // set each row of matrix to display desired char
    lc.setRow(0,i,bytedChar[i]);
  }

  delay(DELAY_TIME);
}

void setup(){
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(DISPLAY_ADDR,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(DISPLAY_ADDR,LED_MATRIX_INENSITY);
  /* and clear the display */
  lc.clearDisplay(DISPLAY_ADDR);
}

void loop(){
  print_char('M');
  print_char('A');
  print_char('N');
  lc.clearDisplay(DISPLAY_ADDR);
  delay(DELAY_TIME);
}
