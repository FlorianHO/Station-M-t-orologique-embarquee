#include <Arduino.h>       // Importation de la bibliothèque Arduino
#include "demarrage.h"     // Importe le fichier demarrage.h contenant la fonction du fichier demarrage.c
#include "standard.h"
#include "configuration.h"
#include "economique.h"
#include "maintenance.h"
#include "Chang_Modes.h"
#include "bouton.h"
#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB

extern int Mode; 

void demarrage() {

    ChainableLED leds(7, 8, 1);     // LED connectée aux pins 7 et 8 et 1 seule LED présente
    Serial.println("Demarrage du système, veuillez patienter...");
    if(millis() < 5000 && digitalRead(2) == LOW)  {
            Serial.println("Lancement du mode configuration.....");
            _delay_ms(1000);
            Mode = 2;
        }
        else {
            Serial.println("Lancement du mode standard.....");
            leds.setColorRGB(0, 0, 255, 0);   // Allume la LED en vert
            _delay_ms(1000);
            Mode = 1;
}}