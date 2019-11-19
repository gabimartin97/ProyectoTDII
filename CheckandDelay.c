/*FUNCION CheckandDelay: Esta funcion se encarga de controlar mediante kbhit() si el usuario
 *ha presionado una tecla al mismo tiempo que genera un delay para las funciones de luces
 * Es necesario que la lectura de las teclas sea independiente del delay entre cada estado
 * de las luces, por lo tanto esta funcion implementa un bucle que chequea el teclado cada 10ms
 * y segun cuantos ciclos de bucle realize ese delay de 10 ms se irá acumulando hasta lograr el
 * delay total deseado. debido a  que cada secuencia de luces tiene su propio delay que debe conservarse
 * esta funcion trabaja con punteros */

#include "kbhit.h"
#include <stdio.h>
#include <unistd.h>
#include "compartidas.h"


char CheckandDelay(int *delay){
	int i;
	char tecla;
	for(i=0;i<*delay;i++){
		usleep(1000); 					// 1ms de delay y luego chequea si se presionó una telca
		/*-----------------------------------------------------------------------------------------*/
			if(kbhit()){ 
				if((tecla=readch())=='\033'){
				readch(); // Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=readch();}
				switch(tecla){
				case 'q': break; //Cuando se presiona una telca y es la tecla q, sale del bucle
				
				case 'A':
				if(*delay>10){*delay=*delay - 5;}  //Si se presiona la flecha de arriba aumenta la velocidad
				break;
				
				case 'B':
				if(*delay< 1000){*delay= *delay +5;} //si se presiona la flecha de abajo la velocidad disminuye
				break;
				
				default:
				break;
			 }
			 
			}
			/*-----------------------------------------------------------------------------------------*/
		
		if(tecla=='q') break;
		
	}
	return tecla;
}
