#include <stdio.h>
#include "EasyPIO.h"
#include <unistd.h>
#include "compartidas.h"
#include "kbhit.h"

int delaySecuencia2=0;
void loopSecuencia2();
void menuSecuencia2();


/*....................................Carrera............................*/
void secuencia2(){
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
        
        menuSecuencia2();
        loopSecuencia2();
        apagar();
        system("clear");
}
/*....................................Carrera............................*/


void loopSecuencia2() {
int i,k;
int c;
//int a;
unsigned char tabla[]={   0b11110000,
				0b00000000,
                0b11110000,
				0b00000000,
				0b11110000,
				0b00000000,
				0b11110000,
				0b00000000,
				0b00001111,
				0b00000000,
				0b00001111,
				0b00000000,
				0b00001111,
				0b00000000,
				0b00001111,
				0b00000000,};
char tecla;
init_keyboard(); //Para kbhit() (keyboardhit)


do{

for(k=0;k<16;k++){

        for(i=0;i<8;i++){
                c = 0b00000001 << i;   //Voy desplazando un 1 en cada iteracion  
                //a = 0b00000000 + c;
                digitalWrite(leds[i],tabla[k] & (c));  //hago una AND entre el 1 y el valor de la tabla correspondiente
}
                    

        tecla=CheckandDelay(&delaySecuencia2); //Llamo a la funcion CheckandDelay que me retorna la tecla presionada sin importar el delay
        if(tecla=='q')break;
}
}while(tecla != 'q');
close_keyboard(); //Para kbhit()
}

void menuSecuencia2(){
        system("clear");
		printf("\n-------------------------------------------\n");
	printf("          EJECUTANDO SECUENCIA EXTRA 2\n");
	printf("            Delay base: %dms ",potenciometro);
	printf("\n-------------------------------------------\n");
	printf("-Pulse la tecla Q para detener la secuencia \n");
	printf("-Puede variar la velocidad con las flechas arriba y abajo \n");

}
