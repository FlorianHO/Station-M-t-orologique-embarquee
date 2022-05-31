#include <Arduino.h>  
#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB
#include "configuration.h"
#include "standard.h"
#include "demarrage.h"
#include "entree_valeur.h"

extern int mode_actuel;
extern int mode_precedent;
extern int Mode;
extern int *PLog_intervalle;
extern int *Ptaille_log;
const long time  = millis();

void configuration() {
    

    ChainableLED leds(7, 8, 1);     // LED connectée aux pins 7 et 8 et 1 seule LED présente
    leds.setColorRGB(0, 165, 120, 0);   // Allume la LED en jaune

    

    if ((millis()-time) > 5000) {
                Mode = 1;
            } 

    Serial.println("1 : LOG_INTERVALLE = ?");
    


   /* 
    
    Serial.println("2 : Taille max d'un fichier LOG");
    Serial.println("3 : RESET");
    Serial.println("4 : Version Programme / Numero de lot");
    Serial.println("5 : Date/heure.");
   unsigned int choix = entree_valeur();

        
        else 
        else if (choix == 2) {
            Serial.println("Veuillez choisir la nouvelle taille du fichier de log :");
            *Ptaille_log = valeur();
            configuration();
            }
        
        else if (choix == 3) {
            Serial.println("Réinitialisation....");
            *PLog_intervalle = 10000;
            *Ptaille_log = 4096;
            Serial.print("Valeurs réinitialisées.");
            configuration();
            }
        else if (choix == 4) {
            Serial.println("La version actuelle du programme est : ");
            configuration();
            }

              */
        
    }

