CC=gcc
CFLAGS=-Wall -I.

proyecto: main.o menu.o acceso.o AutoFantastico.o kbhit.o CheckandDelay.o carrera.o EasyPIO.o compartidas.o
	$(CC) $(CFLAGS) -o proyecto main.o menu.o acceso.o AutoFantastico.o kbhit.o CheckandDelay.o carrera.o EasyPIO.o compartidas.o

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

.PHONY: clean
clean:
	rm *.o 
