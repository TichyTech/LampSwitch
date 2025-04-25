#include "peripherals.h"

void setup_pins(){
  pinMode(BUTTONPIN, INPUT);
  pinMode(LAMPPIN, OUTPUT);
  pinMode(REDLEDPIN, OUTPUT);
  pinMode(BLUELEDPIN, OUTPUT);
  pinMode(GREENLEDPIN, OUTPUT);
  digitalWrite(LAMPPIN, 0);
  digitalWrite(BLUELEDPIN, 1);
  digitalWrite(REDLEDPIN, 0);
  digitalWrite(GREENLEDPIN, 0);
}

void flash_led(uint8_t ledpin, int times, int dl){
  for (int i = 0; i < times; i++){
    digitalWrite(ledpin, 1);
    delay(dl);
    digitalWrite(ledpin, 0);
    delay(dl);
  }
}