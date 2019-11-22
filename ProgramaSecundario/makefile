#MAKEFILE PARA EL PROGRAMA SECUNDARIO DEL PROYECTO FINAL

CC=gcc
CFLAGS= -I.

secuencias= AutoFantastico.o carrera.o ElChoque.o apilada.o

programa2: $(secuencias) programa2.o  SerialCheckandDelay.o EasyPIO.o compartidas.o ADC.o 
	$(CC) $(CFLAGS) -o programa2 $(secuencias) programa2.o  SerialCheckandDelay.o EasyPIO.o compartidas.o ADC.o -lwiringPi

programa2.o: programa2.c
	$(CC) $(CFLAGS) -c -o programa2.o programa2.c

AutoFantastico.o: AutoFantastico.c
	$(CC) $(CFLAGS) -c -o AutoFantastico.o AutoFantastico.c

SerialCheckandDelay.o: SerialCheckandDelay.c
	$(CC) $(CFLAGS) -c -o SerialCheckandDelay.o SerialCheckandDelay.c

carrera.o: carrera.c
	$(CC) $(CFLAGS) -c -o carrera.o carrera.c

EasyPIO.o: EasyPIO.c
	$(CC) $(CFLAGS) -c -o EasyPIO.o EasyPIO.c

compartidas.o: compartidas.c
	$(CC) $(CFLAGS) -c -o compartidas.o compartidas.c

ElChoque.o: ElChoque.c
	$(CC) $(CFLAGS) -c -o ElChoque.o ElChoque.c
	
apilada.o: apilada.c
	$(CC) $(CFLAGS) -c -o apilada.o apilada.c
ADC.o: ADC.c
	$(CC) $(CFLAGS) -c -o ADC.o ADC.c

.PHONY: clean
clean:
	rm *.o 
