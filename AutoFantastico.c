
/* AUTO FANTASTICO */


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

#define SPEED 100  //Setear la velocidad del barrido en  milisegundos
void loopFantastico();
void apagar();
int leds[8]={LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8};


/*....................................main............................*/

void AutoFantastico(){
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

	loopFantastico();
	apagar();
}

/*....................................main............................*/


void loopFantastico() {
int i;

do{

		for (i=0;i<8;i++){
			digitalWrite(leds[i],1);
			if(i!=0)digitalWrite(leds[i-1],0);
			if(digitalRead(sw1)==1)break; //Cuando se presiona el pulsador break
			if(i!=0)usleep(SPEED * 1000); //Delay a excepcion de los extremos
		}
		for (i=7;i>(-1);i--){
			if(digitalRead(sw1)==1)break; //Cuando se presiona el pulsador break
			if(i!=7)digitalWrite(leds[i+1],0);
			digitalWrite(leds[i],1);
			if(i!=7)usleep(SPEED * 1000); //Delay a excepcion de los extremos
			if(digitalRead(sw1)==1)break; //Cuando se presiona el pulsador break
		}


	}while((digitalRead(sw1))!=1); //Cuando se presiona el pulsador se termina 
}

void apagar(){ //Funcion que apaga todos los leds
	digitalWrite(LED1,0);
        digitalWrite(LED2,0);
        digitalWrite(LED3,0);
        digitalWrite(LED4,0);
        digitalWrite(LED5,0);
        digitalWrite(LED6,0);
        digitalWrite(LED7,0);
        digitalWrite(LED8,0);

}



