#include <Arduino.h>  
#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB
#include "maintenance.h"
#include <BME280I2C.h>
#include "temps.h"

extern int mode_actuel;
extern int mode_precedent;
extern int Mode;
extern int *PLog_intervalle;
 

void maintenance() {
   
    mode_actuel = 4;
    mode_precedent = mode_actuel;
    
   ChainableLED leds(7, 8, 1);     // LED connectée aux pins 7 et 8 et 1 seule LED présente
    leds.setColorRGB(0, 255, 40, 0);   // Allume la LED en bleu

    unsigned long Luminosite = analogRead(0);
    Serial.print("Capteur de lumière : ");
    Serial.print(Luminosite);
    Serial.println(" Lumen");
    temps();
    String val = printBME280(&Serial);
    Serial.println(val);
    delay(*PLog_intervalle);
    }