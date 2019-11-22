/*Este archivo cabecera declara todas las funciones que se sefinen en EasyPIO.c y 
 * que leugo seran utilizadas por todos los programas*/
#ifndef EASYPIO_H
#define EASYPIO_H



#define	BCM2837_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2837_PERI_BASE + 0x200000)
volatile unsigned int *gpio; //Puntero a la base de gpio
#define GPLEV0 (*(volatile unsigned int*)(gpio + 13))
#define BLOCK_SIZE (4*1024)

#define GPFSEL ((volatile unsigned int*) (gpio + 0))
#define GPSET ((volatile unsigned int*) (gpio + 7))
#define GPCLR ((volatile unsigned int*) (gpio +10))
#define GPLEV ((volatile unsigned int*) (gpio + 13))
#define INPUT 0
#define OUTPUT 1

void pioInit();
void pinMode();
void digitalWrite();
int digitalRead();




#endif

