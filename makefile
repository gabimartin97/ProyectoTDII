CC=gcc
CFLAGS=-Wall -I.

proyecto: main.o menu.o acceso.o AutoFantastico.o kbhit.o 
	$(CC) $(CFLAGS) -o proyecto main.o menu.o acceso.o AutoFantastico.o kbhit.o

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


.PHONY: clean
clean:
	rm *.o 
