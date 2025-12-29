#include <stdio.h>
#include "pliki.h"
#include "database.h"

Node* wczytajZPliku(Node* head, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik == NULL) {
        printf("Błąd: Nie można otworzyć pliku %s\n", nazwaPliku);
        return head;
    }

    char bufor[128]; // Bufor na jedną linię tekstu

    // Czytamy plik linia po linii
    while (fgets(bufor, sizeof(bufor), plik)) {
        struct Person nowaOsoba;
        int jobInt, statusInt; // Zmienne pomocnicze do wczytania enumów jako int

        // Parsowanie linii: %s (napis), %d (liczby)
        // Uwaga: Zakładamy, że imię nie ma spacji!
        if (sscanf(bufor, "%49s %d %d %d %d",
                   nowaOsoba.name,
                   &jobInt,
                   &nowaOsoba.food,
                   &nowaOsoba.risk,
                   &statusInt) == 5) {

            // Rzutowanie wczytanych intów na Twoje typy enum
            nowaOsoba.job = jobInt;
            nowaOsoba.status = statusInt;

            // Dodanie stworzonej osoby do listy
            head = push_back(head, nowaOsoba);
                   }
    }

    fclose(plik);
    printf("Wczytano dane z pliku %s.\n", nazwaPliku);
    return head;
}

void zapiszDoPliku(Node* head, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");

    if (plik == NULL) {
        printf("Blad: Nie mozna otworzyc pliku %s do zapisu.\n", nazwaPliku);
        return;
    }

    Node* current = head;
    while (current != NULL) {
        // Format musi być identyczny jak przy wczytywaniu:
        // Imie(string) Zawod(int) Jedzenie(int) Ryzyko(int) Status(int)

        fprintf(plik, "%s %d %d %d %d\n",
                current->person.name,
                (int)current->person.job,    // rzutowanie na int dla pewności
                current->person.food,
                current->person.risk,
                (int)current->person.status); // rzutowanie na int

        current = current->next;
    }

    fclose(plik);
    printf("Pomyslnie zapisano liste do pliku: %s\n", nazwaPliku);
}