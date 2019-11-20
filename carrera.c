/* LA CARRERA:*/

#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
#include "kbhit.h"

int delayCarrera=10;
void loopcarrera();
void menucarrera();


/*....................................Carrera............................*/
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
        
        menucarrera();
        loopcarrera();
        apagar();
        system("clear");
}
/*....................................Carrera............................*/


void loopcarrera() {
int i,k;
int c;
//int a;
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
                c = 0b00000001 << i;   //Voy desplazando un 1 en cada iteracion  
                //a = 0b00000000 + c;
                digitalWrite(leds[i],tabla[k] & (c));  //hago una AND entre el 1 y el valor de la tabla correspondiente
}
                    

        tecla=CheckandDelay(&delayCarrera); //Llamo a la funcion CheckandDelay que me retorna la tecla presionada sin importar el delay
        if(tecla=='q')break;
}
}while(tecla != 'q');
close_keyboard(); //Para kbhit()
}

void menucarrera(){
        system("clear");
		printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO LA CARRERA\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");

}


