#include <Arduino.h>
#include "temps.h"
#include "DS1307.h"
#include <BME280I2C.h>
#include <Wire.h>

DS1307 clock;
BME280I2C bme;

String temps() {
    clock.begin();
    clock.getTime();
    String temps = String((clock.hour), DEC);
    temps += String(":");
    temps += String((clock.minute), DEC);
    temps += String(":");
    temps += String((clock.second), DEC);
    temps += String(" ");
    temps += String(clock.dayOfMonth, DEC);
    temps += String("/");
    temps += String(clock.month, DEC);
    temps += String("/");
    temps += String(clock.year+2000, DEC);
    temps += String(" ");
    Serial.println(temps);
    return temps;
}


String printBME280(Stream* client) {

    Wire.begin();

    while (!bme.begin()) {
        Serial.println("Erreur");
    }

    
    String valeur;
    float temp(NAN), hum(NAN), pres(NAN);
    valeur = String(temp);

    BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
    BME280::PresUnit presUnit(BME280::PresUnit_Pa);

    bme.read(pres, temp, hum, tempUnit, presUnit);

    String valc = String("\tTemperature: ");
    valc += String(temp);
    valc += String("°"+ String(tempUnit == BME280::TempUnit_Celsius ? 'C' : 'F'));
    valc += String("\tHumidite: ");
    valc += String(hum);
    valc += String("% RH");
    valc += String("\tPression: ");
    valc += String(pres);
    valc += String("Pa");
    return valc;




}