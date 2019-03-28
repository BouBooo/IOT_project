# Projets IoT - Plante connectée


## A propos

 - Environnement : Linux (Ubuntu)
 - Langage : C++

L’objet connecté intègre un microcontrôleur programmable (intégré sur la carte ZEST_CORE_STM32L496RG), une carte de prototypage sur laquelle sont montée le capteur de température LM75 qui communique en I2C, et un capteur d’humidité analogique, et enﬁn, une carte de communication (Zest_Radio_ATZBRF233) permet de communiquer avec internet grâce à la technologie 6LoWPAN.



## Objectifs

L’objectif du projet et de mettre en oeuvre l’ensembles des technologies présentées en cours pour réaliser un objet connecté qui permettra de remonter des données environnementales vers le Cloud. Diﬀérents services pourrons ensuite être développé pour valoriser ces données, les traiter et interagir avec l’objet.

## Fonctionnalités 

 - Acquisition régulière de la température et de l’humidité 
 - Remonter les données sur la plateforme Cloud adafruit.io grâce au protocole MQTT

## Documentation utilisée

- API Mbed OS : https://os.mbed.com/docs/mbed-os/v5.11/apis/index.html 
- Documentation cartes 6TRON : https://member.6tron.io/fr/m/ressources/ 
- Datasheet LM75 : https://datasheets.maximintegrated.com/en/ds/LM75.pdf
