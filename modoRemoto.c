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

	switch (seleccion){
			case '1':
			menufantastico();  
				do{
				tecla=getchar();
				escritura(tecla);
				}while(tecla!='q');
				break;
			
			case '2':
			
			menucarrera();
				do{
				tecla=getchar();
				escritura(tecla);
				}while(tecla!='q');
			break;
			
			case '3':
			menuchoque();
				do{
				tecla=getchar();
				escritura(tecla);
				}while(tecla!='q');
			break;
			
			case '4':
			
			menuApilada();
				do{
				tecla=getchar();
				escritura(tecla);
				}while(tecla!='q');
			break;
			
			case '5':
			break;
			
			default:
			printf("\n ----------------\n");
			printf("Opcion no valida ");
			printf("\n ----------------\n");
			usleep(600000);
			break;
		}
		
			
	
	
	

}
