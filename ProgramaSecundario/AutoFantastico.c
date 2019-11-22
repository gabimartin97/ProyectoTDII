
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

#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
#include <wiringPi.h>
#include <wiringSerial.h>				



int delayFantastico=10; 		//Las flechas arriba y abajo incrementarán la velocidad del bucle
void loopFantastico();
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
//fd=serialOpen("/dev/ttyAMA0",9600);  //Apertura del puerto serie

do{

		for (i=0;i<8;i++){
			digitalWrite(leds[i],1);
			if(i!=0)digitalWrite(leds[i-1],0);
			if(i!=0)tecla=CheckandDelay(&delayFantastico);
			if(tecla=='q') break;
		}
		
		for (i=7;i>(-1);i--){
			if(tecla=='q') break;
			if(i!=7)digitalWrite(leds[i+1],0);
			digitalWrite(leds[i],1);
			if(i!=7)tecla=CheckandDelay(&delayFantastico);	//Delay a excepcion de los extremos
			if(tecla=='q') break; 				//Cuando se presiona una telca y es la tecla q, sale del bucle
		}


	}while(tecla !='q');		 //Cuando se pulsa q termina el bucle
	//serialClose(fd);
}


void menufantastico(){
	system("clear");
	printf("\n-------------------------------------------\n");
	printf("  EJECUTANDO AUTO FANTASTICO DE MANERA REMOTA\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Envie 'q' para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");
	
}

