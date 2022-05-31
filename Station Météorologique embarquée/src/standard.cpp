#include <Arduino.h>  
#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB
#include <SD.h>
#include <SPI.h>
#include "standard.h"
#include "maintenance.h"
#include "configuration.h"
#include "demarrage.h"
#include <Wire.h>
#include <BME280I2C.h>
#include "temps.h"

File Fichier;
extern int mode_precedent;
extern int mode_actuel;
extern int Mode;
extern int *PLog_intervalle;

void standard() {

    ChainableLED leds(7, 8, 1);     // LED connectée aux pins 7 et 8 et 1 seule LED présente
    leds.setColorRGB(0, 0, 255, 0);   // Allume la LED en vert

    mode_actuel = 1;
    mode_precedent = mode_actuel;
    
    if (!SD.begin(4)) {
        Serial.println("L'initilisation de la carte SD a échoué");
        leds.setColorRGB(0, 255, 0, 0);   // Allume la LED en rouge
        _delay_ms(500);                  // Pause de 1 seconde
        leds.setColorRGB(0, 0, 0, 0);    // Eteint la LED
        _delay_ms(1000);                 // Pause de 2 secondes
        return;                          // Retour au début du if (évite que le programme ne s'arrête)
    }
    Serial.println("Acquisition des données et écriture sur la carte SD en cours");
    
       unsigned long Luminosite = analogRead(0);
        String horloge = temps();
        String bmeval = printBME280(&Serial);
       Fichier = SD.open("fich.csv", FILE_WRITE);
       if (Fichier) {
        Fichier.println(horloge);
        Fichier.print(Luminosite);
        Fichier.println(" Lumen ");
        Fichier.println(bmeval);
        Fichier.close();
        delay(*PLog_intervalle); 
       }
     else {
         Serial.println("Erreur de l'ouverture du fichier");
        return;
}}
        
    


