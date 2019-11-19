/*Aqui se definen todas las funciones y variables que seran comunes a todas las funciones de luces*/

#include "compartidas.h"
#include "EasyPIO.h"

int leds[8]={LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8};

void apagar(){ 					//Funcion que apaga todos los leds
	digitalWrite(LED1,0);
        digitalWrite(LED2,0);
        digitalWrite(LED3,0);
        digitalWrite(LED4,0);
        digitalWrite(LED5,0);
        digitalWrite(LED6,0);
        digitalWrite(LED7,0);
        digitalWrite(LED8,0);

}
