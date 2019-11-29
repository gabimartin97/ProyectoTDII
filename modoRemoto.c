/*ESTA FUNCION SE ENCARGA DE ENVIAR BYTES POR EL PUERTO SERIE PARA QUE EL PROGRAMA SECUNDARIO LOS RECIBA 
 * Y COMANDE LAS FUNCIONES DE LUCES */


#include "wiringPi.h" //WiringPi modificada
#include <stdlib.h>
#include <pcf8591.h> //Wiring pi soporta este sensor
#include "EasyPIO.h"
#include <stdio.h>
#include "compartidas.h"

void modoRemoto(char seleccion){  //la funcion seleccionada llega como parametro de la funcion
char tecla;
int def=0; //default
	switch (seleccion){
			case '1':
			menufantastico();  
			break;
			
			case '2':
			menucarrera();
			break;
			
			case '3':
			menuchoque();
			break;
			
			case '4':
			menuApilada();
			break;
			
			case '5':
			menuSecuencia1();
			break;
			
			case '6':
			menuSecuencia2();
			break;
			
			case '7':
			menuSecuencia3();
			break;
			
			case '8':
			menuSecuencia4();
			break;
			
			case '9':
			break;
			
			default:
			def=1;
			printf("\n ----------------\n");
			printf("Opcion no valida ");
			printf("\n ----------------\n");
			usleep(600000);
			break;
			}
			
			
			if(def!=1){
			do{
				tecla=getchar();
				escritura(tecla);
				}while(tecla!='q');
		}
		else {
			def=0;
		}
	write('q'); // Enviamos varias 'q' por si hay un error en la reciepcion del byte 'q' y para evitar desincronismo
	usleep(1000);
	write('q');
	

}
