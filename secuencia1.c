#include "kbhit.h"
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
		
int delaySecuencia1=0; 		//Las flechas arriba y abajo incrementarán la velocidad del bucle
void loopSecuencia1();
void menuSecuencia1();

/*....................................main............................*/
void secuencia1(){
	int i;
	pioInit();   			 //No olvidarse de pioInit
	for(i=0;i<8;i++) pinMode(leds[i],OUTPUT); //Declaro leds como salida
	menuSecuencia1();
	loopSecuencia1();
	apagar();
	system("clear");
}
/*....................................main............................*/

void loopSecuencia1() {
int i,j;
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)


do{
	for(j=0;j<4;j++){
		for (i=3;i>(-1);i--){
			if(i!=3)digitalWrite(leds[i+1],0);
			digitalWrite(leds[i],1);
			tecla=CheckandDelay(&delaySecuencia1);
			if(tecla=='q') break;
			if(i==0){digitalWrite(leds[i],0);
			tecla=CheckandDelay(&delaySecuencia1);}
			if(tecla=='q') break;
		}
		if(tecla=='q') break;
	}
	if(tecla != 'q'){	
	
	for(j=0;j<4;j++){	
		for (i=4;i<8;i++){
			digitalWrite(leds[i],1);
			if(i!=4)digitalWrite(leds[i-1],0);
			tecla=CheckandDelay(&delaySecuencia1);
			if(tecla=='q') break;
			if(i==7){digitalWrite(leds[i],0);
			tecla=CheckandDelay(&delaySecuencia1);}
			if(tecla=='q') break; 				//Cuando se presiona una telca y es la tecla q, sale del bucle
		}
		if(tecla=='q') break;
	}
}

	}while(tecla !='q');		 //Cuando se pulsa q termina el bucle
	close_keyboard();		//Para kbhit()
}


void menuSecuencia1(){
	system("clear");
	printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO SECUENCIA EXTRA 1\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");
	
}
