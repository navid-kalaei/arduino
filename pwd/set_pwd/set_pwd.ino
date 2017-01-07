/*
 * set initial pwd to eeprom
 */


// From http://playground.arduino.cc/Code/EepromUtil
// this is a cumtom lib with a merge of EepromUtil.cpp and EepromUtil.h
#include "EepromUtil.h"

//password address, it's default value in official example so it's better not to be changed
#define PWD_ADDR 100
#define PWD "Hello, World!"


const int BUFSIZE = 50;
char buf[BUFSIZE];


int i;

void clear_buffer() {
  for (i = 0; i < BUFSIZE; i++) {
    buf[i] = 0;
  }
}

void setup() {
  while(!Serial.available());
  Serial.println("Saving password to eeprom...");
  strcpy(buf, PWD);
  EepromUtil::eeprom_write_string(PWD_ADDR, buf);
  clear_buffer();
  EepromUtil::eeprom_read_string(PWD_ADDR, buf, BUFSIZE);
  Serial.print("Password set to: '");
  Serial.print(buf);
  Serial.println("'");
}

void loop() {
}
