/* Aqui se definen todas las funciones que se utilizarán para el manejo de GPIO
 * basandose en el la bibliografia de la catedra*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include "EasyPIO.h"

void pioInit(){
	int mem_fd;
	void *reg_map;

// /dev/mem is a pseudo-driver for accessing memory in Linux
	mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
	reg_map = mmap(
	 NULL,
	 BLOCK_SIZE,
	 PROT_READ | PROT_WRITE,
	 MAP_SHARED,
	 mem_fd,
	 GPIO_BASE);

	gpio = (volatile unsigned *)reg_map;
	close(mem_fd);

}

void pinMode(int pin, int function){
	int reg = pin/10;
	int offset = (pin%10)*3;

	GPFSEL[reg]&= ~((0b111 & ~function) << offset);
	GPFSEL[reg]|= ((0b111 & function) << offset);
}

void digitalWrite(int pin, int val){
	int reg = pin/32;
	int offset = pin%32;

	if(val) GPSET[reg]=1 << offset;
	else 	 GPCLR[reg]=1 << offset;
}

int digitalRead(int pin){
	int reg = pin/32;
	int offset = pin%32;
	return(GPLEV[reg]>>offset)& 0x00000001;

}


