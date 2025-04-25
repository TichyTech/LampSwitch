#ifndef PERPH
#define PERPH

#include <Arduino.h>

#define HOSTNAME "MyHostName"
#define REDLEDPIN 14
#define GREENLEDPIN 16
#define BLUELEDPIN 2
#define LAMPPIN 4
#define BUTTONPIN 13

void setup_pins();
void flash_led(uint8_t ledpin, int times, int dl);

#endif