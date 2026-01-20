CC = gcc
CFLAGS = -Wall
all: BazaOcalalych
BazaOcalalych: main.o database.o menu.o pliki.o raport.o walidacja.o
	$(CC) $(CFLAGS) -o BazaOcalalych main.o database.o menu.o pliki.o raport.o walidacja.o

main.o: main.c database.h menu.h pliki.h raport.h walidacja.h
	$(CC) $(CFLAGS) -c main.c

database.o: database.c database.h
	$(CC) $(CFLAGS) -c database.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

pliki.o: pliki.c pliki.h
	$(CC) $(CFLAGS) -c pliki.c

raport.o: raport.c raport.h
	$(CC) $(CFLAGS) -c raport.c

walidacja.o: walidacja.c walidacja.h
	$(CC) $(CFLAGS) -c walidacja.c

run: all
	./BazaOcalalych

clean:
	rm -f *.o BazaOcalalych BazaOcalalych.exe