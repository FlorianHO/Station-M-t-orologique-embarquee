L'objectif était de réaliser une station météorologique embarquée avec une carte Arduino et des capteurs en langage C++ (sur Visual Studio Code).

Le matériel défini pour valider une première version du système est le suivant :
·	Microcontrôleur : AVR ATmega328 qui est intégré à la carte Arduino qui servira à concevoir le prototype.
·	Composants :
-	Lecteur de carte SD (SPI) qui permettra la sauvegarde des données des capteurs
-	Horloge RTC (I2C) qui permettra au système de connaître la date et l'heure du jour.
-	LED RGB (2-wire) qui permettra de communiquer l'état du système
-	2 boutons poussoirs (numériques) qui permettront l'interaction avec le système
·	Capteurs :
-	Pression atmosphérique (I2C ou SPI)
-	Température de l'air (I2C ou SPI)
-	Hygrométrie (I2C ou SPI)
-	GPS (UART)
-	Luminosité (analogique)
·	Modules complémentaires qui seront intégrés au projet par la suite :
-	Température de l'eau (analogique)
-	Force du courant marin (I2C)
-	Force du vent (I2C)
-	Taux de particules fines (2-wire)

Voici un descriptif des différents modes :

Mode standard: Le système récupère à intervalle régulier la valeur des capteurs (l’intervalle entre 2 mesures est de 10 minutes par défaut mais configurable grâce au paramètre LOG_INTERVAL). 
L’ensemble des mesures est enregistré sur une seule ligne horodatée. La donnée associée à un capteur ne répondant pas au bout d’un temps défini par le paramètre TIMEOUT (par défaut 30s) sera “NA”. 
Ces données sont enregistrées sur la carte SD dans un fichier dont la taille est définie par le paramètre FILE_MAX_SIZE (2ko par défaut). Les noms des fichiers prendront la forme suivante : 200531_0.LOG (Année=20, mois=05, jour=31, numéro de révision=0).
Le système écrit toujours dans le fichier dont le numéro de révision est 0. 
Quand un fichier est plein, le système crée une copie du fichier avec le numéro de révision adapté puis recommence à enregistrer les données au début du fichier (révision 0).

Mode configuration: Ce mode permet de configurer le système grâce à une interaction depuis une console sur l’interface série du microcontrôleur (UART). Depuis l'interface série on pourra taper des commandes de configuration pour modifier les valeurs des paramètres enregistrés dans l’EEPROM : LOG_INTERVALL=10 -> définition de l’intervalle entre 2 mesures, 10 minutes par défaut. FILE_MAX_SIZE=4096 -> définition de la taille maximale (en octets) d'un fichier de log, une taille de 4ko provoque son archivage. 
RESET -> réinitialisation de l’ensemble des paramètres à leurs valeurs par défaut. VERSION -> affiche la version du programme et un numéro de lot (permet de tracer la production).
Pour les différents capteurs: TIMEOUT=30 -> durée (en s) au bout de laquelle l’acquisition des données d’un capteur est abandonnée. Après 2 mesures en timeout, le capteur est signalé en erreur.

Mode maintenance : Les données ne sont plus écrites sur la carte SD mais peuvent être consultées en direct depuis le port série. La carte SD peut être retirée et replacée en toute sécurité. 

Mode économie : L’acquisition des données du GPS n’est plus effectuée qu’une mesure sur deux et le temps entre 2 mesure (LOG_INTERVAL) est multiplié par 2 tant que le système est dans ce mode.
