/*PROYECTO FINAL TDII:PROGRAMA 2: ESTE PROGRAMA SERA EJECTUADO POR LA SEGUNDA RASPBERRY QUE
 * RECIBIRA COMANDOS DE MANERA REMOTA MEDIANTE PUERTO SERIE. LA ESTRUCTURA ES MUY SIMILAR AL PROGRAMA PRINCIPAL
 * CON LA UNICA DIFERENCIA QUE LOS COMANDOS SE TOMAN POR PUERTO SERIE Y NO POR TECLADO
 * EL PROGRAMA FUNCIONA CON WIRINGPI.H. SE INTENTO HACER LECTURA Y ESCRITURA MEDIANTE TERMIOS Y FUNCIONES DE BAJO NIVEL
 * PERO NO SE LOGRABAN RESULTADOS SATISFACTORIOS, ESPECIALMENTE PORQUE NO SE PUDO REEMPLAZAR LA FUNCION SerialDataAvail() 
 * QUE SI TRAE WIRING PI  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wiringPi.h"
#include <wiringSerial.h>
#include <pcf8591.h> //Wiring pi soporta este sensor
#include "compartidas.h"

void submenu();
int potenciometro;
char serialpotenciometro;
int main(void)
{
	char seleccion;
	int fd;
	if (wiringPiSetup () == -1) exit (1); //Inicializa Wiring PI y Chequea errores
	pcf8591Setup(BASE, Address);   		  //Configuracion del ADC
	
	do{
		submenu();
		fd=serialOpen("/dev/ttyAMA0",9600);    //Abro puerto serie
		seleccion=serialGetchar(fd); 			//Leo el dato que viene por puerto serie. el codigo no sigue hasta que llega el dato o pasan unos segundos
		
		if(seleccion=='@'){				//El @ me indica que el proximo dato es el valor del potenciometro
			 serialpotenciometro=serialGetchar(fd);		//tomo el valor char
			 potenciometro=(serialpotenciometro -'0');  //y lo transforomo en int
			 seleccion=serialGetchar(fd);}				//leo el proximo dato
			 serialClose(fd);
		//potenciometro=ADC();							//Descomentar esta linea y borrar las anteriores si se desea leer el ADC de la placa 2
		if(potenciometro<0) potenciometro=1;		//por las dudas
		if(potenciometro==0) potenciometro++;  		//para que no se produzca error cuando el potenciometro esta en 0
			
	switch(seleccion){
					
			case '1':
			AutoFantastico(); 						//Cada funcion debe imprimir en pantalla su propio menu de ejecuccion
			break;
			
			case '2':
			Carrera();
			break;
			
			case '3':
			ElChoque();
			break;
			
			case '4':
			apilada();
			break;
			
			case '5':
			secuencia1();
			break;
			
			case '6':
			secuencia2();
			break;
			
			case '7':
			secuencia3();
			break;
			
			case '8':
			secuencia4();
			break;
			
			case '9':
			break;
			
			default:
			system("clear");
			printf("\n  Dato no válido \n "); 
			break;
		}
	
	}while(seleccion != '9');    //9 hace salir al programa
	
		return 0;
}


void submenu(){  												//Menu para las funciones de luces
		system("clear"); 										//Limpia el texto en la terminal
		printf("\n PROGRAMA SECUNDARIO DEL PROYECTO FINAL \n");
		printf("\n INGRESE DATOS MEDIANTE PUERTO SERIE A 9600 BAUDIOS  \n ");
		printf("1- Auto Fantastico \n ");
		printf("2- La carrera\n ");
		printf("3- El choque\n ");
		printf("4- La apilada\n ");
		printf("5- Secuencia extra 1\n ");
		printf("6- Secuencia extra 2\n ");
		printf("7- Secuencia extra 3\n ");
		printf("8- Secuencia extra 4\n ");
		printf("9- SALIR\n ");
		//potenciometro=ADC();								//Leo el valor del potenciometro del adc, descomentar para utilizar potenciometro local
		printf("Delay base (potenciometro): %dms \n",potenciometro);
				
	}

