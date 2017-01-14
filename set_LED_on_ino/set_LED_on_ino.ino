/**
 * Set LED on
 * use this program to reset board
 *
 * @author: Navid Kalaei <navidkalaei@gmail.com>
 */

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000)
}
