CC=gcc
CFLAGS=-Wall -I.

proyecto: main.o menu.o acceso.o 
	$(CC) $(CFLAGS) -o proyecto main.o menu.o acceso.o 


main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o


menu.o: menu.c
	$(CC) $(CFLAGS) -c -o menu.o menu.c

acceso.o: acceso.c
	$(CC) $(CFLAGS) -c -o acceso.o acceso.c

.PHONY: clean
clean:
	rm *.o 
