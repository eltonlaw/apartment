#include "ESP8266WiFi.h"

int PIN_OUT = 3;

void setup() {
  pinMode(PIN_OUT, OUTPUT);     // Initialize the PIN_OUT pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_OUT, LOW);
  delay(500);
  digitalWrite(PIN_OUT, HIGH); 
  delay(500);
  digitalWrite(PIN_OUT, LOW);   
  delay(500);                      // Wait for a second
  digitalWrite(PIN_OUT, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2500);                      // Wait for two seconds (to demonstrate the active low LED)
}
