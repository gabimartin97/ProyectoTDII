#include "kbhit.h"
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"

int delaySecuencia3=0; 		//Las flechas arriba y abajo incrementarán la velocidad del bucle
void loopSecuencia3();
void menuSecuencia3();

/*....................................main............................*/

void secuencia3(){
	int i;
	pioInit();   			 //No olvidarse de pioInit
	for(i=0;i<8;i++) pinMode(leds[i],OUTPUT); //Declaro leds como salida
	menuSecuencia3();
	loopSecuencia3();
	apagar();
	system("clear");
}
/*....................................main............................*/

void loopSecuencia3() {
int i;
char tecla;
for(i=0;i<8;i++) digitalWrite(leds[i],1); //Prendo todos los leds
init_keyboard(); //Para kbhit() (keyboardhit)
//Aveces demora en salir o ignora la tecla q
do{
	for (i=0;i<9;i++){
			digitalWrite(leds[i],0);
			if(i!=0)digitalWrite(leds[i-1],1);
			if(digitalRead(sw1)==1)break; //Cuando se presiona el pulsador break
			tecla=CheckandDelay(&delaySecuencia3);
			if(tecla=='q') break; 
		}
	

}while(tecla !='q');		 //Cuando se pulsa q termina el bucle
	close_keyboard();		//Para kbhit()
}

void menuSecuencia3(){
	system("clear");
	printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO SECUENCIA EXTRA 3\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");
	
}

