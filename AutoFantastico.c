
			/* AUTO FANTASTICO */
/*ESTA  FUNCION UTILIZA UNA FUNCION/PROGRAMA QUE SAQUE DE INTERNET: kbhit(), HACE REFERENCIA A
 * KEYBOARD HIT. LA MISMA DEVUELVE UN 1 CUANDO EL USUARIO PULSA CUALQUIER TECLA DEL TECLADO.
 * ES UTIL PORQUE SI UTILIZAMOS GETCHAR() EL PROGRAMA QUEDA CONGELADO ESPERANDO QUE PULSEMOS ALGO 
 * Y LA SECUENCIA DE LUCES SE CONGELA TAMBIEN. CON kbhit() EL PROGRAMA NO SE DETIENE
 * ADEMÁS TAMBIEN INCLUYE LA FUNCION init_keyboard() close_keyboard() que lo que hacen es manejo de
 * ficheros en termios.h (como la funcion acceso) para desactivar el modo canonico y el echo
 * POR ULTIMO LA FUNCION readch() TAMBIEN FORMA PARTE DE ESTE PAQUETE Y DEVUELVE EL VALOR DE LA TECLA
 * PULSADA. CUALQUIER COSA VER kbhit.h y kbhit.c */
/*----------------------------------------------------------------------------------------------*/
#include "kbhit.h"
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
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
int leds[8]={LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8};
				/*todos estos define son prolijos pero es mucho codigo al pedo */
#define SPEED 1 		//Setear la velocidad base del barrido. !La tiene que dar el conversor AD!
int incremento=100; 		//Las flechas arriba y abajo incrementarán la velocidad del bucle
void loopFantastico();
void apagar();
void menufantastico();



/*....................................main............................*/

void AutoFantastico(){
	pioInit();   			 //No olvidarse de pioInit
	pinMode(LED1,OUTPUT);		//Esto podria compactarse con un for
	pinMode(LED2,OUTPUT);
	pinMode(LED3,OUTPUT);
	pinMode(LED4,OUTPUT);
	pinMode(LED5,OUTPUT);
	pinMode(LED6,OUTPUT);
	pinMode(LED7,OUTPUT);
	pinMode(LED8,OUTPUT);
	pinMode(sw1,INPUT);
	
	menufantastico();
	loopFantastico();
	apagar();
	system("clear");
}

/*....................................main............................*/


void loopFantastico() {
int i;
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)

do{

		for (i=0;i<8;i++){
			digitalWrite(leds[i],1);
			if(i!=0)digitalWrite(leds[i-1],0);
			/*-----------------------------------------------------------------------------------------*/
			if(kbhit()){ 
				if((tecla=readch())=='\033'){
				readch(); // Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=readch();}
				switch(tecla){
				case 'q': break; //Cuando se presiona una telca y es la tecla q, sale del bucle
				
				case 'A':
				if(incremento>1)incremento=incremento - 10;
				break;
				
				case 'B':
				if(incremento < 1000)incremento= incremento +10;
				break;
				
				default:
				break;
			 }
			}
			/*-----------------------------------------------------------------------------------------*/
			if(i!=0)usleep((SPEED + incremento)  * 1000); //Delay a excepcion de los extremos
			if(tecla=='q') break;
		}
		
		for (i=7;i>(-1);i--){
			if(tecla=='q') break;
			/*-----------------------------------------------------------------------------------------*/
			if(kbhit()){
			if((tecla=readch())=='\033'){
				readch(); // Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=readch();}
				switch(tecla){
				case 'q': break; //Cuando se presiona una telca y es la tecla q, sale del bucle
				
				case 'A':
				if(incremento>1)incremento=incremento - 10;
				break;
				
				case 'B':
				if(incremento < 1000)incremento= incremento +10;
				break;
				
				default:
				break;
			 }
			}
			/*-----------------------------------------------------------------------------------------*/
			if(i!=7)digitalWrite(leds[i+1],0);
			digitalWrite(leds[i],1);
			if(i!=7)usleep((SPEED + incremento) * 1000); 	//Delay a excepcion de los extremos
			if(tecla=='q') break; 				//Cuando se presiona una telca y es la tecla q, sale del bucle
		}


	}while(tecla !='q');		 //Cuando se pulsa q termina el bucle
	close_keyboard();		//Para kbhit()
}

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

void menufantastico(){
	system("clear");
	printf("\n-------------------------------------------\n");
	printf("EJECUTANDO AUTO FANTASTICO");
	printf("\n-------------------------------------------\n");
	printf("Pulse la tecla q para detener la secuencia \n");
	printf("Puede variar la velocidad con las flechas arriba y abajo \n");
}

