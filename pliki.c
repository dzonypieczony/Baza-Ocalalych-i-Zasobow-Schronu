#include <stdio.h>
#include "pliki.h"
#include "database.h"

Node* read_file(Node* head, char* file_name) {
    FILE* plik = fopen(file_name, "r");
    if (plik == NULL) {
        printf("\nBlad: Nie mozna otworzyc pliku %s", file_name);
        return head;
    }
    char bufor[128]; // Bufor na jedną linię tekstu
    // Czytamy plik linia po linii
    while (fgets(bufor, sizeof(bufor), plik)) {
        struct Person nowaOsoba;
        int jobInt, statusInt; // Zmienne pomocnicze do wczytania enumów jako int
        // Parsowanie linii: %s (napis), %d (liczby)
        // Uwaga: Zakładamy, że imię nie ma spacji!
        if (sscanf(bufor, "%49s %d %d %d %d %d",
                   nowaOsoba.name,
                   &jobInt,
                   &nowaOsoba.food[0],
                   &nowaOsoba.food[1],
                   &nowaOsoba.risk,
                   &statusInt) == 6) {
            // Rzutowanie wczytanych intów na Twoje typy enum
            nowaOsoba.job = jobInt;
            nowaOsoba.status = statusInt;
            // Dodanie stworzonej osoby do listy
            head = push_back(head, nowaOsoba);}
    }
    fclose(plik);
    return head;
}

void write_file(Node* head, char* file_name) {
    FILE* plik = fopen(file_name, "w");
    if (plik == NULL) {
        printf("\nBlad: Nie mozna otworzyc pliku %s", file_name);
        return;
    }
    Node* current = head;
    while (current != NULL) {
        // Format musi być identyczny jak przy wczytywaniu:
        // Imie(string) Zawod(int) Jedzenie(int) Ryzyko(int) Status(int)

        fprintf(plik, "%s %d %d %d %d %d\n",
                current->person.name,
                (int)current->person.job,    // rzutowanie na int dla pewności
                current->person.food[0],
                current->person.food[1],
                current->person.risk,
                (int)current->person.status); // rzutowanie na int
        current = current->next;
    }
    fclose(plik);
    printf("\nPomyslnie zapisano liste do pliku");
}