#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"


int delaySecuencia4=0;
void loopSecuencia4();
void menuSecuencia4();


/*....................................Carrera............................*/
void secuencia4(){
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
        
        menuSecuencia4();
        loopSecuencia4();
        apagar();
        system("clear");
}
/*....................................Carrera............................*/


void loopSecuencia4() {
int i,k;
int c;
unsigned char tabla[]={   0b00000001,
                                0b10000000,
                0b00000010,
                                0b01000000,
                0b00000100,
                                0b00100000,
                0b00001000,
                                0b00010000,
                0b00010000,
                                0b00001000,
                0b00100000,
                                0b00000100,
                0b01000000,
                                0b00000010,
                0b10000000,
                                0b00000001,
                0b00000001,
                                0b00000010,
                0b00000100,
                                0b00001000,
                0b00010000,
                                0b00100000,
                0b01000000,
                                0b10000000,
                0b10000000,
                                0b01000000,
                0b00100000,
                                0b00010000,
                0b00001000,
                                0b00000100,
                0b00000010,
                                0b00000001};

char tecla;

do{

for(k=0;k<32;k++){

        for(i=0;i<8;i++){
                c = 0b00000001 << i;   //Voy desplazando un 1 en cada iteracion  
                //a = 0b00000000 + c;
                digitalWrite(leds[i],tabla[k] & (c));  //hago una AND entre el 1 y el valor de la tabla correspondiente
}

                    

        tecla=CheckandDelay(&delaySecuencia4); //Llamo a la funcion CheckandDelay que me retorna la tecla presionada sin importar el delay
        if(tecla=='q')break;
}

}while(tecla != 'q');

}

void menuSecuencia4(){
        system("clear");
		printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO SECUENCIA EXTRA 4\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");

}
