/* PROGRAMA PRINCIPAL MAIN: ESTA FUNCION SERA EL NúCLEO DEL PROYECTO E IRA LLAMANDO A TODAS LAS DEMAS FUNCIONES */

#include <stdio.h>
#include <stdlib.h>
//#include "acceso.c"  (Si usamos makefile no hace hay que incluirlas porque nos da errror de doble declaracion)
//#include "menu.c"

int main(int argc, char **argv)
{
	char a;
	a=acceso();
	if (a==1) menu();
	else printf("\n Acceso denegado \n");
	return 0;
}

