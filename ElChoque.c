
/* EL CHOQUE */


#include "kbhit.h"
#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
void loopChoque();
void menuchoque();
int delayChoque=0;
/*....................................main............................*/
void ElChoque(){
	int i;
	pioInit();    //No olvidarse de pioInit
	for(i=0;i<8;i++) pinMode(leds[i],OUTPUT); //Declaro leds como salida
	menuchoque();
	loopChoque();
	apagar();
	system("clear");
}
/*....................................main............................*/

void loopChoque() {
int i;
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)
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
	close_keyboard(); //Para kbhit() 
}
void menuchoque(){
        system("clear");
		printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO EL CHOQUE\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");

}




