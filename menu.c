/*FUNCION MENÚ: ES LA FUNCION QUE INTERACTÚA CON EL USUARIO Y LO DERIVA A LOS DIVERSOS PROGRAMAS. */
/*JUNTO CON LA FUNCION SUBMENU DECLARADA DENTRO SON LA PARTE "GRAFICA" DEL PROGRAMA */

/*#include "AutoFantastico.c" Si usamos makefile no hay que incluirlas porque nos da errror de doble declaracion)*/
/* El mismo makefile crea los objetos por separado y los linkea */
/*-----------------------------------------------------------------------------------------------------------------*/
#include "wiringPi.h" //WiringPi modificada
#include <stdlib.h>
#include <pcf8591.h> //Wiring pi soporta este sensor
#include "EasyPIO.h"
#include <stdio.h>
#include "compartidas.h"
char seleccion; 											//Es variable de tipo char
int potenciometro;											//Viene del ADC
char submenu();												//Imprime texto y retorna seleccion
int secuencias(char seleccion);								//Segun la seleccion ejectua una secuencia de luces


int menu()
{	
	system("clear"); 										//Limpia el texto en la terminal
	printf("\nBIENVENIDO AL MEJOR PROYECTO FINAL DE LA HISTORIA \n");	
	printf("Seleccione el método de trabajo \n");
	printf("1- LOCAL\n");
	printf("2- REMOTO\n");
	printf("9- SALIR\n");
	do{
		seleccion=getchar();
		switch(seleccion){
			
			case '1':		//LOCAL
				do{
					system("clear"); 										//Limpia el terminal
					printf("------------LOCAL--------------");
					seleccion=submenu();				//Submenu indica que secuencia de luces queremos
					secuencias(seleccion);				//
				}while(seleccion!='9');					//9= exit
			break;
			
			case '2':		//REMOTO
				do{
					system("clear"); 										//Limpia el terminal
					printf("------------REMOTO--------------");
					printf("Se enviara un byte por puerto serie segun la opcion elegida");
					seleccion=submenu();				//Submenu indica que secuencia de luces queremos
					escritura(seleccion); //envio el dato ------->
					modoRemoto(seleccion);
										
				}while(seleccion!='9');	
			break;
			
			case '9':		//SALIR
			break;
			
			default:
			printf("Opcion no valida \n");
			break;
		}
	}while(seleccion !='9');
		
	
	return 0;
}


char submenu(){  												//Menu para las funciones de luces
	//do{
		
		printf("\n Seleccione la secuencia de luces a ejecutar \n ");
		printf("1- Auto Fantastico \n ");
		printf("2- La carrera\n ");
		printf("3- El choque\n ");
		printf("4- La apilada\n ");
		printf("5- Secuencia extra 1\n ");
		printf("6- Secuencia extra 2\n ");
		printf("9- SALIR\n ");
		potenciometro=ADC();								//Leo el valor del potenciometro del adc
		printf("Delay base (potenciometro): %dms \n",potenciometro);
		
		seleccion=getchar();
		return seleccion;
	}
	
	int secuencias(char seleccion){
		switch(seleccion){
			case '1':
			potenciometro=ADC();
			if(potenciometro==0)      				//para que no se produzca error cuando el potenciometro esta en 0
			potenciometro++;
			AutoFantastico(); 						//Cada funcion debe imprimir en pantalla su propio menu de ejecuccion
			break;
			
			case '2':
			potenciometro=ADC();
			if(potenciometro==0)
			potenciometro++;
			Carrera();
			break;
			
			case '3':
			potenciometro=ADC();
			if(potenciometro==0)
			potenciometro++;
			ElChoque();
			break;
			
			case '4':
			potenciometro=ADC();
			if(potenciometro==0)
			potenciometro++;
			apilada();
			break;
			
			case '5':
			potenciometro=ADC();
			if(potenciometro==0)
			potenciometro++;
			secuencia1();
			break;
			
			case '6':
			potenciometro=ADC();
			if(potenciometro==0)
			potenciometro++;
			secuencia2();
			break;
			
			case '9':
			break;
			
			default:
			printf("\n ----------------\n");
			printf("Opcion no valida ");
			printf("\n ----------------\n");
			usleep(600000);
			break;
		}
		return 0;
	}//while(seleccion !='5');
	
	

