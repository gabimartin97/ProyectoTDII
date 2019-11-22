CC=gcc
CFLAGS= -I.

secuencias= AutoFantastico.o carrera.o ElChoque.o apilada.o

proyecto: $(secuencias) main.o menu.o acceso.o kbhit.o CheckandDelay.o EasyPIO.o compartidas.o ADC.o escritura.o termset.o modoRemoto.o
	$(CC) $(CFLAGS) -o proyecto $(secuencias) main.o menu.o acceso.o kbhit.o CheckandDelay.o EasyPIO.o compartidas.o ADC.o escritura.o termset.o modoRemoto.o -lwiringPi

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

menu.o: menu.c 
	$(CC) $(CFLAGS) -c -o menu.o menu.c

acceso.o: acceso.c
	$(CC) $(CFLAGS) -c -o acceso.o acceso.c

AutoFantastico.o: AutoFantastico.c
	$(CC) $(CFLAGS) -c -o AutoFantastico.o AutoFantastico.c

kbhit.o: kbhit.c
	$(CC) $(CFLAGS) -c -o kbhit.o kbhit.c

CheckandDelay.o: CheckandDelay.c
	$(CC) $(CFLAGS) -c -o CheckandDelay.o CheckandDelay.c

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

escritura.o: escritura.c
	 $(CC) $(CFLAGS) -c -o escritura.o escritura.c

termset.o: termset.c
	$(CC) $(CFLAGS) -c -o termset.o termset.c

modoRemoto.o: modoRemoto.c
	$(CC) $(CFLAGS) -c -o modoRemoto.o modoRemoto.c
.PHONY: clean
clean:
	rm *.o 
