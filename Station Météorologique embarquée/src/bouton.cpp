#include <Arduino.h>
#include "bouton.h"

extern int Mode;
extern int mode_precedent;

  boolean LongPressure(byte button) {
     for (int i = 1; i<=10; i++) {
        if (digitalRead(button) == HIGH) {
           Mode = mode_precedent;
        return false;
        break;
     }
     else if (i == 10) {
        return true;
     }
     delay(500);
  }}