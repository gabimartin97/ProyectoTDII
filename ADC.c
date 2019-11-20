//EJERCICIO 7
//Asegurarse de tener instalada WiringPi, de tener habilitados los puertos i2c en la rasp.
  
  
  #include "wiringPi.h" //WiringPi modificada
  #include <stdlib.h>
  #include <stdio.h>
  #include <pcf8591.h> //Wiring pi soporta este sensor
  #include "EasyPIO.h"
  #include "compartidas.h"
  
  
  
  int ADC(void){
   	int val;
   	
    	
   	
   	
    //El modulo usa 3.3v de referencia divididos en 255 escalones (8 bits).
    // El conversor nos devolverá un valor digital segun la entrada analógioca,
    //Por lo tanto para pasarlo a mV hay que multiplicarlo por 3300/255
    
            
   		val = analogRead(A0); //Leo, convierto y escribo 
   		//printf("A0 (Potenciometro): %d mv\n",val);
   		
   	
  return val;
   }
