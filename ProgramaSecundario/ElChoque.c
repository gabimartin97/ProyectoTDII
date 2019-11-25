
/* EL CHOQUE */

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"


void loopChoque();
void menuchoque();
int delayChoque=10;


/*....................................main............................*/

void ElChoque(){
	pioInit();    //No olvidarse de pioInit
	pinMode(LED1,OUTPUT);
	pinMode(LED2,OUTPUT);
	pinMode(LED3,OUTPUT);
	pinMode(LED4,OUTPUT);
	pinMode(LED5,OUTPUT);
	pinMode(LED6,OUTPUT);
	pinMode(LED7,OUTPUT);
	pinMode(LED8,OUTPUT);
	pinMode(sw1,INPUT);
	
	menuchoque();
	loopChoque();
	apagar();
	system("clear");
}

/*....................................main............................*/


void loopChoque() {
int i;
char tecla;
//fd=serialOpen("/dev/ttyAMA0",9600);  //Apertura del puerto serie
do{

		for (i=0;i<8;i++){
			digitalWrite(leds[i],1);
			if(i!=0 && i!=4)digitalWrite(leds[i-1],0);
						
			digitalWrite(leds[7-i],1);
			if(i!=0 && i!=4 )digitalWrite(leds[8-i],0);

			tecla=CheckandDelay(&delayChoque); //Llamo a la funcion CheckandDelay que me retorna la tecla presionada sin importar el delay
            if(tecla=='q')break;
		}
	


	}while(tecla !='q'); //Cuando se presiona el pulsador se termina
	//serialClose(fd);
}
void menuchoque(){
        system("clear");
		printf("\n-------------------------------------------\n");
	printf("  EJECUTANDO EL CHOQUE DE MANERA REMOTA\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Envie 'q' para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");

}




