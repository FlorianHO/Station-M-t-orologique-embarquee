#include <Arduino.h>       // Importation de la bibliothèque Arduino
#include <ChainableLED.h>  // Importation de la bibliothèque ChainableLED permettant de gérer la LED RGB
#include "demarrage.h"     // Importe le fichier demarrage.h contenant la fonction du fichier demarrage.c
#include "standard.h"      // Importe le fichier demarrage.h contenant la fonction du fichier demarrage.c
#include "configuration.h" // Importe le fichier demarrage.h contenant la fonction du fichier demarrage.c
#include "economique.h"    // Importe le fichier economique.h contenant la fonction du fichier economique.c
#include "maintenance.h"   // Importe le fichier maintenance.h contenant la fonction du fichier maintenance.c
#include "Chang_Modes.h"   // Importe le fichier Chang_Modes.h contenant la fonction du fichier Chang_Modes.c
#include "bouton.h"        // Importe le fichier bouton.h contenant la fonction du fichier bouton.c

int Mode = 0;
int Log_interval = 10000;
int *PLog_intervalle = &Log_interval;
int mode_actuel;
int mode_precedent;
int taille_log = 4096;
int *Ptaille_log = &taille_log;

void setup() {
  Serial.begin(9600);        // Iniatalise la connexion série à 9600 bauds(bits/s)
  pinMode(2, INPUT);         // Déclaration de la broche 2 en tant que sortie
  pinMode(3, INPUT);         // Déclaration de la broche 3 en tant que sortie
  demarrage();               // Appel de la procédure demarrage
  attachInterrupt(digitalPinToInterrupt(3), Chang_Modes2, FALLING);      // Iniatalise la première interruption sur la broche 3, et qui activer a la fonction changement
  attachInterrupt(digitalPinToInterrupt(2), Chang_Modes1, FALLING);      // Iniatalise la seconde interruption sur la broche 2, et qui activer a la fonction changement2
}     

void loop() {
switch(Mode) {
    case 1:
       standard();
       break;
    case 2:
       configuration();
       break;
    case 3:
       economique();
       break;
    case 4:
       maintenance();
       break;
    case 5:
      if(LongPressure(2) == true) {
         if (mode_precedent == 1) {
            Mode = 4;
            break;
         }
         else if (mode_precedent == 4) {
            Mode = 1;
            break;
         }
         else if (mode_precedent == 3) {
            Mode = 4;
            break;
         }
         else {
            break;
         }
      }
    case 6:
    if(LongPressure(3) == true) {
         if (mode_precedent == 1) {
            Mode = 3;
            break;
         }
         else if (mode_precedent == 3) {
            Mode = 1;
            break;
         }
         else if (mode_precedent == 4) {
            Mode = 3;
            break;
         }
         else {
            break;
         }}}}
