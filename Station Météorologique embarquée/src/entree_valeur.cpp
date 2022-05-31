#include <Arduino.h>
#include "entree_valeur.h"

int entree_valeur() {
    String entree;
    Serial.println("Veuillez entrer le nombre correspondant :");
    while (Serial.available() == 0 && entree == NULL) {
        entree = Serial.readString();
    }
    Serial.print("Vous avez choisi : ");
    Serial.println(entree);
    return entree.toInt();
}

int valeur() {
    String valeur;
    Serial.println("Veuillez entrer la valeur : ");
    while (Serial.available() == 0 && valeur == NULL) {
        valeur = Serial.readString();
    }
    Serial.print("Vous avez choisi : ");
    Serial.println(valeur);
    return valeur.toInt();
}

