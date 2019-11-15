/* LA CARRERA: ESTE PROGRAMA UTILIZA EL MISMO HEADER (EASYPIO.H) QUE AUTO FANTASTICO
 * POR LO TANTO EL COMPILADOR SE ENOJA POR MULTIPLE DEFINICION DE VARIABLES
 * HAY QUE VER COMO SE SOLUCIONA ESTO. POR EL MOMENTO ESTE PROGRAMA NO ESTA EN 
 * MAKEFILE NI EN menu(); */


#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include <math.h>
#include "kbhit.h"


#define SPEED 1 //Velocidad base. Debe estar dada por el conversor AD

void loopcarrera();
void apagar();

extern int leds[8];

/*....................................main............................*/
void Carrera(){
        pioInit(); //No olvidarse de pioInit
        pinMode(LED1,OUTPUT);
        pinMode(LED2,OUTPUT);
        pinMode(LED3,OUTPUT);
        pinMode(LED4,OUTPUT);
        pinMode(LED5,OUTPUT);
        pinMode(LED6,OUTPUT);
        pinMode(LED7,OUTPUT);
        pinMode(LED8,OUTPUT);
        pinMode(sw1,INPUT);

        loopcarrera();
        apagar();
        system("clear");
}
/*....................................main............................*/
void loopcarrera() {
int incremento2=100;
int i,k,a;
int c=0;
int tabla[]={   0b00000001,
				0b00000001,
                0b00000010,
				0b00000010,
                0b00000100,
				0b00000100,
                0b00001000,
				0b00001000,
                0b00010001,
				0b00010010,
                0b00100100,
				0b00101000,
                0b01010000,
				0b01100000,
                0b11000000,
				0b10000000};
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)

do{

for(k=0;k<16;k++){

        for(i=0;i<8;i++){
                c = pow(2,i);
                a=0b00000000+c;
                digitalWrite(leds[i],tabla[k] & (a));
}

                      /*-----------------------------------------------------------------------------------------*/
			if(kbhit()){ 
				if((tecla=readch())=='\033'){
				readch(); // Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=readch();}
				switch(tecla){
				case 'q': break; //Cuando se presiona una telca y es la tecla q, sale del bucle
				
				case 'A':
				if(incremento2>1)incremento2=incremento2 - 10;
				break;
				
				case 'B':
				if(incremento2 < 1000)incremento2= incremento2 +10;
				break;
				
				default:
				break;
			 }
			}
			/*-----------------------------------------------------------------------------------------*/

usleep((SPEED+incremento2)*1000);

c=0;
if(tecla=='q')break;
}
}while(tecla != 'q');
close_keyboard();
}



/* void apagar(){ //Funcion que apaga todos los leds
        digitalWrite(LED1,0);
        digitalWrite(LED2,0);
        digitalWrite(LED3,0);
        digitalWrite(LED4,0);
        digitalWrite(LED5,0);
        digitalWrite(LED6,0);
        digitalWrite(LED7,0);
        digitalWrite(LED8,0);
}*/
