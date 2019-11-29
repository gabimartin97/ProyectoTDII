#include "kbhit.h"
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
				
int delayApilada=0; 		//Las flechas arriba y abajo incrementarán la velocidad del bucle
void loopApilada();
void menuApilada();

/*....................................main............................*/

void apilada(){
	pioInit();   			 //No olvidarse de pioInit
	for(i=0;i<8;i++) pinMode(leds[i],OUTPUT); //Declaro leds como salida
	menuApilada();
	loopApilada();
	apagar();
	system("clear");
}

/*....................................main............................*/

void loopApilada() {
int i;
int n=8;
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)

do{

		for (i=0;i<=n;i++){
			digitalWrite(leds[i],1);
			if(i!=0)digitalWrite(leds[i-1],0);
			tecla=CheckandDelay(&delayApilada);
			if(tecla=='q') break;
		}
		
	    if(tecla!='q'){
		digitalWrite(leds[n-1],0);
		tecla=CheckandDelay(&delayApilada);
		if(tecla=='q') break;
		digitalWrite(leds[n-1],1);
		n=n-1;
		if(n == 0){
			 digitalWrite(leds[n],0);
			tecla=CheckandDelay(&delayApilada);
			if(tecla=='q') break;
			digitalWrite(leds[n],1);
			tecla=CheckandDelay(&delayApilada);
			apagar();
			n=8;
		}
	} 
	else;
	}while(tecla!='q');		 //Cuando se pulsa q termina el bucle
	close_keyboard();		//Para kbhit()
}


void menuApilada(){
	system("clear");
	printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO LA APILADA\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");
}
