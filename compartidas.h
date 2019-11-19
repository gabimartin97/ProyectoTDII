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
#define SPEED 100 		//Setear la velocidad base del barrido. !La tiene que dar el conversor AD!

extern int leds[8];
void apagar();


 


#endif
