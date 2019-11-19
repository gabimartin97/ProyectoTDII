/* FUNCION ACCESO: ESTA FUNCION SE ENCARGA DE PERMITIRNOS ACCEDER O NO AL PROGRAMA MEDIANTE CONTRASEÑA. */
/* LA FUNCION RETORNA 1 SI LA CONTRASEÑA ES CORRECTA Y 0 SI NO LO ES */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define password "12345" // Setear la contraseña
#define maxlenght 20 //Máxima lognitud del vector contraseña

struct termios orig_termios; //Declaracion de la variable orig_termios de la estructura de tipo termios
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); // retornamos los parametros originales 
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios); //tcgetattr() to read the current attributes into a struct. Copiamos los atributos a la variable orig_termios
  atexit(disableRawMode); //Llama a la funcion disable automáticamente al salir del programa

  struct termios raw = orig_termios; //creamos la variable local raw y le pasamos los datos de la estructura original
  raw.c_lflag &= ~(ECHO | ICANON); // modificamos el dato c_lflag de la variable raw. Realiza una bit wise and y desp asigna. (&= notacion abreviada )
  // (~) --> bitwise NOT operator
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //escribimos los nuevos atributos modificados 
}

/*--------------------------------------------------------------*/


int acceso()
{
	char pass[maxlenght]=password;
	char entry[maxlenght]="";
	char c;
	int n=2,i=0,x;
		
	printf(" \n Inserte la contraseña para acceder al sistema \n"); //Primera pregunta
	enableRawMode(); // Desactivamos el echo y el modo canonico 
	
	while((c=getchar()) != '\n'){
	  printf("*");
	  entry[i]=c;  //Rellenamos la cadena entry con la contraseña tipeada
	  i++;
  }
  entry[i+1]='\0'; //colocamos final de cadena
  i=0;

//En caso de errarle, se entra en este bucle y se tienen 3 intentos antes de errarle

	while(strcmp(entry,pass)!= 0){ //Si se compara entry con la contraseña verdadera y da distinto
		printf("\n Contraseña incorrecta, intentos restantes %i",n);
		printf(" \n Ingrese nuevamente la constrasena\n");
		
	
		for(x=0;x<maxlenght;x++){  //Este bucle simplemente limpia toda la cadena entry para poder reescribirla
		entry[x]='\0';
		//if(x==(maxlenght - 1)) printf("\n string cleared \n");
		}
		
	
		while((c=getchar()) != '\n'){
		printf("*");
		entry[i]=c;
		i++;
	    }
		entry[i+1]='\0'; //Colocamos final de cadena
		i=0;
	
		if(n==1) break;
		n=n-1;// decrecen los intentos para acertarar
		}
	  
	  //si se acabaron los intentos
  if(n==1 && strcmp(entry,pass)!= 0){
		  printf("\n Se acabaron los intentos");
		  return 0;
		 }
		 //O si se ingreso correctamente
  else{ // printf("\n Bienvenido al sistema");
    return 1;
    }
	
	
}

