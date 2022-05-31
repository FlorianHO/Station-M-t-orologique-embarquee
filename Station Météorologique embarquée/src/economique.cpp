#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB
#include <SD.h>
#include <SPI.h>
#include "economique.h"
#include "temps.h"

extern int *PLog_intervalle;
extern int mode_actuel;
extern int mode_precedent;
extern int Mode;

File Fichier2;
void economique() {

    mode_actuel = 3;
    mode_precedent = mode_actuel;
    ChainableLED leds(7, 8, 1);     // LED connectée aux pins 7 et 8 et 1 seule LED présente
    leds.setColorRGB(0, 0, 0, 255);   // Allume la LED en bleu
       unsigned long Luminosite = analogRead(0);
        String horloge = temps();
        String bmeval = printBME280(&Serial);
       Fichier2 = SD.open("fich.csv", FILE_WRITE);
       if (Fichier2) {
        Fichier2.println(horloge);
        Fichier2.print(Luminosite);
        Fichier2.println(" Lumen ");
        Fichier2.println(bmeval);
        Fichier2.close();
        delay(*PLog_intervalle*2); 
       }
     else {
         Serial.println("Erreur de l'ouverture du fichier");
        return;
}
}