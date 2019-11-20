/*FUNCION CheckandDelay: Esta funcion se encarga de controlar mediante kbhit() si el usuario
 *ha presionado una tecla al mismo tiempo que genera un delay para las funciones de luces
 * Es necesario que la lectura de las teclas sea independiente del delay entre cada estado
 * de las luces, por lo tanto esta funcion implementa un bucle que chequea el teclado cada 10ms
 * y segun cuantos ciclos de bucle realize ese delay de 10 ms se irá acumulando hasta lograr el
 * delay total deseado. debido a  que cada secuencia de luces tiene su propio delay que debe conservarse
 * esta funcion trabaja con punteros */
 /*ESTA  FUNCION UTILIZA UNA FUNCION/PROGRAMA QUE SAQUE DE INTERNET: kbhit(), HACE REFERENCIA A
 * KEYBOARD HIT. LA MISMA DEVUELVE UN 1 CUANDO EL USUARIO PULSA CUALQUIER TECLA DEL TECLADO.
 * ES UTIL PORQUE SI UTILIZAMOS GETCHAR() EL PROGRAMA QUEDA CONGELADO ESPERANDO QUE PULSEMOS ALGO 
 * Y LA SECUENCIA DE LUCES SE CONGELA TAMBIEN. CON kbhit() EL PROGRAMA NO SE DETIENE
 * ADEMÁS TAMBIEN INCLUYE LA FUNCION init_keyboard() close_keyboard() que lo que hacen es manejo de
 * ficheros en termios.h (como la funcion acceso) para desactivar el modo canonico y el echo
 * POR ULTIMO LA FUNCION readch() TAMBIEN FORMA PARTE DE ESTE PAQUETE Y DEVUELVE EL VALOR DE LA TECLA
 * PULSADA. CUALQUIER COSA VER kbhit.h y kbhit.c */

#include "kbhit.h"
#include <stdio.h>
#include <unistd.h>
#include "compartidas.h"
int potenciometro;

char CheckandDelay(int *delay){
	int i;
	char tecla;
	for(i=0;i<(*delay+potenciometro);i++){
		usleep(1000); 					// 1ms de delay y luego chequea si se presionó una telca
		/*-----------------------------------------------------------------------------------------*/
			if(kbhit()){ 
				if((tecla=readch())=='\033'){
				readch(); // Nos deshacemos de [. ver como funciona el readch() de una telca especial
				tecla=readch();}
				switch(tecla){
				case 'q': break; //Cuando se presiona una telca y es la tecla q, sale del bucle
				
				case 'A':
				if((*delay+potenciometro)>10){*delay=*delay - 5;}  //Si se presiona la flecha de arriba aumenta la velocidad
				break;
				
				case 'B':
				if((*delay+potenciometro)< 1000){*delay= *delay +5;} //si se presiona la flecha de abajo la velocidad disminuye
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
