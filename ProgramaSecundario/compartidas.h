/*HEADER QUE CONTIENEN VARIABLES y FUNCIONES EN COMUN PARA TODOS LOS PROGRAMAS DE LUCES
 * Las variables se declaran aquí con extern y luego se definen
 * en los compartidas.c */
 /*Se hace de esta forma porque sino el linkeador encuentra multiples declaraciones y definiciones
  * de varaibles */

#ifndef compartidas
#define compartidas

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 12
#define LED5 16
#define LED6 20
#define LED7 21
#define LED8 26
#define sw1  17
#define sw2  27

  /* -------------------------SETUP DEL ADC------------------*/
  #define Address 0x48  //Dirección del puerto I2C en el sensor, 0x48 default
  #define BASE 64 //The Base can be any number you like above 64
  #define A0 BASE+0 // Potenciometro. El pin 0 adopta el valor de la base
  #define A1 BASE+1 //Fotocelda
  #define A2 BASE+2 //Termistor
  #define A3 BASE+3 //Conectado a GND

extern int leds[8];
extern int potenciometro;
void apagar();


 


#endif
