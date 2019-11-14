

#include <stdio.h>
#include <stdlib.h>
//#include "acceso.c"
//#include "menu.c"

int main(int argc, char **argv)
{
	char a;
	a=acceso();
	if (a==1) menu();
	else printf("\n que haces gato \n");
	return 0;
}

