#include <Arduino.h>                  // Importation de la bibliothèque Arduino
#include "standard.h"                // Importation de la bibliothèque Arduino
#include "maintenance.h"           // Importation de la bibliothèque Arduino
#include "economique.h"            // Importation de la bibliothèque Arduino
#include "configuration.h"        // Importation de la bibliothèque Arduino

extern int Mode;
extern int mode_precedent;
extern int mode_actuel;
extern bool bouton;

void Chang_Modes1() {
    Mode = 5;
    
  }

void Chang_Modes2() {
    Mode = 6;
  }

