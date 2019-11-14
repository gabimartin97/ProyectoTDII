#include <stdio.h>
//#include "AutoFantastico.c"
char seleccion; //Es variable de tipo char
int submenu();
int menu()
{
	system("clear"); //Limpia el terminal
	printf("\n BIENVENIDO AL MENU CAJETILLA \n ");	
	printf("Seleccione el método de trabajo \n ");
	printf("1- LOCAL\n");
	printf("2- REMOTO\n ");
	printf("5- SALIR\n");
	do{
		seleccion=getchar();
		switch(seleccion){
			case '1':
			submenu();
			break;
			
			case '2':
			submenu();
			break;
			
			case '5':
			break;
			
			default:
			printf("Opcion no valida \n");
			break;
		}
	}while(seleccion !='5');
		
	
	return 0;
}


submenu(){
	system("clear"); //Limpia el terminal
	printf("\n Seleccione la secuencia de luces a ejecutar \n ");
	printf("1- Auto Fantastico \n ");
	printf("2- La carrera\n ");
	printf("3- El choque\n ");
	printf("5- SALIR\n ");
	
	do{
		seleccion=getchar();
		switch(seleccion){
			case '1':
			//AutoFantastico();
			break;
			
			case '2':
			break;
			
			case '3':
			break;
			
			case '5':
			break;
			
			default:
			printf("Opcion no valida \n");
			break;
		}
	}while(seleccion !='5');
	return 0;
	
}
