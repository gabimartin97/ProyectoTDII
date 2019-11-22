/*FUNCION SerialCheckandDelay:Esta funcion es exactamente igual a CheckandDelay con la diferencia
 * que los comandos se reciben por puerto serie y no por teclado. hecho con WiringPi por sencillez*/

//#include "kbhit.h"
#include <stdio.h>
#include <unistd.h>
#include "compartidas.h"
#include <wiringPi.h>
#include <wiringSerial.h>
int potenciometro;

char CheckandDelay(int *delay){
	int i,fd;
	char tecla;
	fd=serialOpen("/dev/ttyAMA0",9600);  //Apertura del puerto serie
	for(i=0;i<(*delay+potenciometro);i++){
		usleep(1000); 					// 1ms de delay y luego chequea si hay dato serie
		/*-----------------------------------------------------------------------------------------*/
				if(serialDataAvail(fd)!=0){
				if((tecla=serialGetchar(fd))=='\033'){ 	// Si se presiono una flecha el primer caracter es \033
				serialGetchar(fd); 						// Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=serialGetchar(fd);}
				switch(tecla){
				case 'q': break; 						//Cuando el dato es q, sale del bucle
				
				case 'A':
				if((*delay+potenciometro)>10 && *delay>5){*delay=*delay - 5;}  //Si se presiona la flecha de arriba aumenta la velocidad
				break;
				
				case 'B':
				if((*delay+potenciometro)< 1000){*delay= *delay +5;} //si se presiona la flecha de abajo la velocidad disminuye
				break;
				
				default:
				break;
				} 
			 serialFlush(fd);  //Descartamos todos los datos presentes en el puero serie
			}
			/*-----------------------------------------------------------------------------------------*/
		
		if(tecla=='q') break;
		
	}
	serialClose(fd);
	return tecla;
}
