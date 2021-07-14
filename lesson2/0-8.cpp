#include "SevSeg.h"

SevSeg sevseg;

byte numDigits = 1; 
byte digitPins[] = {3, 2, 2, 2}; 
byte segmentPins[] = {7, 6, 5, 10, 11, 8, 9, 4}; 
byte hardwareConfig = COMMON_CATHODE ; 
int readValue = 0; 
int showValue = 0; 

void setup() {
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins); 
}

void loop() {
  readValue = analogRead(A0); 
  showValue = map(readValue, 0, 1023, 0, 9); 
  sevseg.setNumber(showValue, 1); 
  sevseg.refreshDisplay(); 
}

