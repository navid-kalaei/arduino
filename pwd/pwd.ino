/*
	Suppose to be a password storage whit ability of changing password


	created on October 10, 2016
	by Navid Kalaei <navidkalaei@gmail.com>
*/


#include "EepromUtil.h"

#define SERIAL_RATE 9600
#define TIMEOUT_TIME 1000

//password address, it's default value in official example so it's better not to be changed
#define PWD_ADDR 100
#define PWD "Hello, World!"

const int BUFSIZE = 50;
char buf[BUFSIZE];

const String changePWDCommand = "change pwd";
String pwd;
String userInput;

bool isEntered;
bool isHelpPrinted;

int i;


void clear_buffer() {
  for (i = 0; i < BUFSIZE; i++) {
    buf[i] = 0;
  }
}

void string_to_buffer(String str) {
  for(i = 0; i != str.length(); i++){
    buf[i] = str[i];
  }
}

void setup() {
  Serial.begin(SERIAL_RATE);
  Serial.setTimeout(TIMEOUT_TIME);
  isEntered = false;
  isHelpPrinted = false;
  clear_buffer();
  EepromUtil::eeprom_read_string(PWD_ADDR, buf, BUFSIZE);
  pwd = String(buf);
  while(!Serial.available());
}


void loop() {
  if(!isHelpPrinted){
    Serial.println("To change password enter: change pwd");
    Serial.println("Other wise enter password to log in");
    isHelpPrinted = !isHelpPrinted;
  }
  if(!isEntered){
    userInput = Serial.readString();
    if(userInput == pwd){
      isEntered = true;
      Serial.println("You've Entered! :D");
    }
    else if(userInput == changePWDCommand){
      Serial.println("Enter new password before timeout: ");
      pwd = Serial.readString();
      clear_buffer();
      string_to_buffer(pwd);
      if(EepromUtil::eeprom_write_string(PWD_ADDR, buf)){
        Serial.print("Password change to: '");
        Serial.print(pwd);
        Serial.println("'");
      }
      else{
        Serial.println("time out!!!");
      }
    }
    else{
      Serial.println("Wrong Password! :|");
    }
  }
}
